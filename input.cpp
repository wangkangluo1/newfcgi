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
	regex expression("(&|^)key=[^&]{1,}");
	cmatch result;

	if(regex_search(str, result, expression) )
		{
			//std::cout << result.str() << std::endl;
			cout<<result.size()<<endl;
			for(int i=0;i<result.size();i++)
				{
					cout<<result[i].str()<<endl;
				}
		}
	else
		{
			cout<<"Error Input"<<endl;
		}
	cout<<"1111111"<<endl;
}
