#include "egg.h"
#include <map>
#include  "query.h"
#include  "output.h"
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
    output output_str;
	std::string op;

	output_str.set_random(input_strs->get("random_str"));
	
	if((op = input_strs->get("op")) == "")
		{
			return output_str.get_str_void();
		}
    query query_str;
	query_str.add("title", input_strs->get("keywords"));
	HEGGTOPCOLLECTOR hTopCollector = eggTopCollector_new(0);
	int ret = eggIndexSearcher_search_with_query(paths->get_search(), hTopCollector, query_str.get_query());
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
					map<char *, char *> ele;
					ele["body"] = val;
					output_str.add(ele);
					
                    
					
					lp_field = 0;
					eggDocument_delete(lp_eggDocument);
				}
		}
	eggTopCollector_delete(hTopCollector);
	return output_str.get_str();
}
