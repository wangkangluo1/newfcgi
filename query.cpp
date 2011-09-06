#include "query.h"

query::query()
{
	query_str = NULL;
}

query::~query()
{
	eggQuery_delete(query_str);
}


void query::add(const char *keywords, std::string key)
{
	
	HEGGQUERY new_query;
	new_query = eggQuery_new_string(keywords, key.c_str(), key.length(), ANALYZER_CWSLEX);
	if(query_str == NULL)
		{
			query_str = new_query;		
		}
	
}

HEGGQUERY	query::get_query()
{
	return query_str;
}







