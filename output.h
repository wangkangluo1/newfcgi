#ifndef OUTPUT_H_
#define OUTPUT_H_
#include <map>

#include	<cstdlib>
#include	<fstream>
#include	<iomanip>   
#include	<iostream>  

extern "C"
{
	#include <glib.h>
}

using namespace std;


class output
{
 public:
	output();
	virtual ~output();
	string *get_str_void();
	string *get_str();
	void add(map<char *, char *> ele);
	void set_random(string str);
 private:
    GString * p_gstr;
	string random_str;
};
#endif
