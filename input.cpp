#include "input.h"
#include <boost/regex.hpp>
#include <boost/algorithm/string/replace.hpp>

extern "C"
{
#include        <sys/time.h>
#include        <unistd.h>
#include   <string.h>

}

using namespace std;
using namespace boost;

input::input(const char *str)
{
	input_strs =(char*)str;
}

input::~input()
{
}

string input::get(char *search_arg)
{
	string gets("(&|^)");
   	gets.append(search_arg);
	gets.append("=[^&]{1,}");
	regex expression(gets.c_str());
	cmatch result;
	if(regex_search(input_strs, result, expression) )
		{
			string strs = result.str();
            replace_first(strs, search_arg, "");
			replace_first(strs, "&", "");
			replace_first(strs, "=", "");
			return strs;
		}
	else
		{
			return "";
		}	
}

 
