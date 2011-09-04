#include "input.h"

#include <boost/regex.hpp>

using namespace std;
using namespace boost;
void input::init(char *str)
{
    input_strs = str;
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
			string searchString( "&" ); 
			string::size_type pos = 0;
			while ( (pos = strs.find(searchString, pos)) != string::npos ) {
				strs.replace( pos, searchString.size(), "" );
				pos++;
			}
			return strs;
		}
	else
		{
			cout<<"Error Input"<<endl;
			return NULL;
		}	
}

 
