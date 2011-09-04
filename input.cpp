#include "input.h"
#include	<cstdlib>
#include	<fstream>
#include	<iomanip>   
#include	<iostream>  
#include <boost/regex.hpp>

using namespace std;
using namespace boost;
void input::init(char *str)
{
    input_strs = str;
}


char * input::get(char *search_arg)
{
	string gets("(&|^)");
   	gets.append(search_arg);
	gets.append("=[^&]{1,}");
	//regex expression("(&|^)key=[^&]{1,}");
	regex expression(gets.c_str());
	cmatch result;
	if(regex_search(input_strs, result, expression) )
		{
			cout << result.str() << std::endl;
		}
	else
		{
			cout<<"Error Input"<<endl;
		}	
}

 
