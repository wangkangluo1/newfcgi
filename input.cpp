#include "input.h"
#include <boost/regex.hpp>

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
	//regex expression("(&|^)key=[^&]{1,}");
	regex expression(gets.c_str());
	cmatch result;
	if(regex_search(input_strs, result, expression) )
		{
			string strs = result.str();
			string::size_type pos = 0;
			if ( (pos = strs.find("&", 0)) != string::npos )
				{
					strs.replace( pos, 1, "" );
				}

			if ( (pos = strs.find(search_arg, 0)) != string::npos )
				{
					strs.replace( pos, strlen(search_arg)+1, "" );
				}
			return strs;
		}
	else
		{
			return "";
		}	
}

 
