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
#include    "input.h"
#include    "egg.h"

using namespace std;

extern "C"
{
#include <stdio.h> 
#include <stdlib.h> 
#include <fcgiapp.h>
}


#ifndef DEBUG
#define printf(...) FCGX_FPrintF(request->out, __VA_ARGS__)
#endif
#define get_param(KEY) FCGX_GetParam(KEY, request->envp) 


void handle_request(FCGX_Request *request, path *paths) { 
    char *value;
	printf("Content-Type: text/plain\r\n\r\n");
	string *back;
	if ((value = get_param("QUERY_STRING")) != NULL)
	{
	
			input inputs(value);
			egg egg_result(paths,&inputs);   //初始化egg容器
			back = egg_result.get_result(); //取结果
	}
	printf("%s",back->c_str());
	delete back;
} 

int
main ( int argc, char *argv[] )
{
    path egg_path;
#ifdef DEBUG
	input inputs(argv[1]);     //初始化输入对象
	cout<<inputs.get("op")<<endl;
	egg egg_result(&egg_path,&inputs);   //初始化egg容器
	string *back = egg_result.get_result();  //取结果
	cout<<back->c_str()<<endl;
	delete back;

#else
	FCGX_Request request; 
    FCGX_Init(); 
    FCGX_InitRequest(&request, 0, 0); 
    while (FCGX_Accept_r(&request) >= 0) { 
        handle_request(&request, &egg_path); 
        FCGX_Finish_r(&request); 
    } 
#endif
    return EXIT_SUCCESS;
	
}
