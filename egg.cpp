#include "egg.h"
using namespace std;

egg::egg(path *egg_path, input *inputs)
{
	input_strs = inputs;
	paths = egg_path;
}

egg::~egg()
{
}

std::string *egg::get_result()
{
	std::string *back = new std::string;
	string op = input_strs->get("op");
	if(op == "")
		{
			return NULL;
		}
	HEGGQUERY h1, h2, h3;
	h1 = eggQuery_new_string("title", "new", 3, ANALYZER_CWSLEX);
	h2 = eggQuery_new_string("content", "new", 3, ANALYZER_CWSLEX);
	h1 = eggQuery_or(h2, h1);
	HEGGTOPCOLLECTOR hTopCollector = eggTopCollector_new(0);
	int ret = eggIndexSearcher_search_with_query(paths->get_search(), hTopCollector, h1);
	if (ret == EGG_TRUE)
		{
			eggTopCollector_normalized(hTopCollector, EGG_TOPSORT_SCORE);
			// eggTopCollector_normalized(hTopCollector, EGG_TOPSORT_NOT);
			HEGGSCOREDOC lp_score_doc = eggTopCollector_top_docs(hTopCollector);
			count_t cnt =  eggTopCollector_total_hits(hTopCollector);
			
			if (cnt > 0)
				{
					HEGGDOCUMENT lp_eggDocument = EGG_NULL;
					eggIndexReader_get_document(paths->get_reader(),
												lp_score_doc[cnt-1].idDoc, &lp_eggDocument);
					HEGGFIELD lp_field = eggDocument_get_field(lp_eggDocument, "content");
					unsigned len = 0;
				    char *val = eggField_get_value(lp_field, &len);
					*back = "last document: body:";
					back->append(val);
					lp_field = 0;
					eggDocument_delete(lp_eggDocument);
				}
		}
	eggTopCollector_delete(hTopCollector);
	eggQuery_delete(h1);
	return back;
}
