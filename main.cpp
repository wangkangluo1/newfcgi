/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/04/2011 03:23:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  kangle.wang (mn), wangkangluo1@gmail.com
 *        Company:  APE-TECH
 *
 * =====================================================================================
 */


#include	<cstdlib>
#include	<fstream>
#include	<iomanip>   
#include	<iostream>
#include    "config.h"

using namespace std;
extern global G;



extern "C"
{
#include <stdio.h> 
#include <stdlib.h> 
#include <fcgiapp.h>
#include <egg2/Egg2.h>
#include <scholar/ImLexAnalyzer.h>
#include <scholar/ImTokenList.h>
#include <scholar/ImCnLexAnalyzer.h>
#include <scholar/ImCwsLexAnalyzer.h>
}




#ifndef DEBUG
#define printf(...) FCGX_FPrintF(request->out, __VA_ARGS__)
#endif
#define get_param(KEY) FCGX_GetParam(KEY, request->envp) 


void me(FCGX_Request *request)
{
	HEGGDIRECTORY hDirectory = eggDirectory_open("/ape/ImRoBot5/index/bas/k2d/");
	HEGGINDEXREADER hIndexReader = eggIndexReader_open(hDirectory);
	HEGGINDEXSEARCHER hIndexSearcher = eggIndexSearcher_new(hIndexReader);
	HEGGQUERY h1, h2, h3;
	h1 = eggQuery_new_string("title", "new", 3, ANALYZER_CWSLEX);
	h2 = eggQuery_new_string("content", "new", 3, ANALYZER_CWSLEX);
	// h2 = eggQuery_new_string("body", "some description", 16, p_la);
	// h3 = eggQuery_new_int32("price", 199);
	// h2 = eggQuery_and(h3, h2);
	h1 = eggQuery_or(h2, h1);
	// h3 = h2 = 0;
	HEGGTOPCOLLECTOR hTopCollector = eggTopCollector_new(0);
	int ret = eggIndexSearcher_search_with_query(hIndexSearcher, hTopCollector, h1);
	if (ret == EGG_TRUE)
		{
			eggTopCollector_normalized(hTopCollector, EGG_TOPSORT_SCORE);
			// eggTopCollector_normalized(hTopCollector, EGG_TOPSORT_NOT);
			HEGGSCOREDOC lp_score_doc = eggTopCollector_top_docs(hTopCollector);
			count_t cnt =  eggTopCollector_total_hits(hTopCollector);
			printf("have hit %u documents\n", cnt);

			if (cnt > 0)
				{
					printf("last document: id[%llu]\n", lp_score_doc[cnt-1].idDoc);
					HEGGDOCUMENT lp_eggDocument = EGG_NULL;
					eggIndexReader_get_document(hIndexReader,
												lp_score_doc[cnt-1].idDoc, &lp_eggDocument);
					HEGGFIELD lp_field = eggDocument_get_field(lp_eggDocument, "content");
					unsigned len = 0;
					char *val = eggField_get_value(lp_field, &len);
					printf("last document: body[%.*s]\n", len, val);
					lp_field = 0;
					eggDocument_delete(lp_eggDocument);
				}
		}

	eggTopCollector_delete(hTopCollector);
	eggQuery_delete(h1);
	eggIndexSearcher_delete(hIndexSearcher);
	eggIndexReader_close(hIndexReader);
	eggDirectory_close(hDirectory);
}


void handle_request(FCGX_Request *request) { 
    char *value;
	printf("Content-Type: text/plain\r\n\r\n"); 
    if ((value = get_param("QUERY_STRING")) != NULL) { 
  		G.inputs.init(value);
	} 
	me(request);
    printf("fuckof\n");
	//printf("%d", G);
} 


int main(void) {
#ifdef DEBUG
	G.inputs.init("&op=me=ni&key=");
	G.inputs.get("op");
	
#else
    //int sock; 
    FCGX_Request request; 

    FCGX_Init(); 
    //sock = FCGX_OpenSocket(":2005", 5); 
    FCGX_InitRequest(&request, 0, 0); 

    while (FCGX_Accept_r(&request) >= 0) { 
        handle_request(&request); 
        FCGX_Finish_r(&request); 
    } 
#endif
    return EXIT_SUCCESS;
	
}
