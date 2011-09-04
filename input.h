#ifndef INPUT_H_
#define INPUT_H_

#include	<cstdlib>
#include	<fstream>
#include	<iomanip>   
#include	<iostream>  


class input
{
 private:
	char *input_strs;
	
 public:
	void init(char *str);
	std::string get(char *search_arg);
};

#endif
