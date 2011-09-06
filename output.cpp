#include  "output.h"

output::output()
{
	 p_gstr = g_string_new(NULL);
}

output::~output()
{
	g_string_free(p_gstr, TRUE); 
}

string *output::get_str_void()
{
	g_string_sprintfa(p_gstr, "_ape_json_.back && _ape_json_.back({\n \
         random_str:%s, \n \
        \"result\":0,  \n \
        \"pageAct\":0, \n \
        \"useTime\":0, \n \
        \"body\":[ \n \
                 {\"post_title\":\"\",\n \
                  \"post_summary\":\"\",\n \
                  \"post_url\":\"\",\n \
                  \"date\":\"\"}\n \
               ],\n \
        \"err\":\"\"})",random_str.c_str());
	
	string *strs = new string(p_gstr->str);
	return strs;
}

void output::set_random(string str)
{
    random_str = (str == "") ? "0" : str;
}

string *output::get_str()
{
	
}



void output::add(map<char *, char *> ele)
{
	
}
