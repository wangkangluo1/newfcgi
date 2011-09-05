#include "config.h"
#include	<cstdlib>
#include	<fstream>
#include	<iomanip>   
#include	<iostream>  
using namespace std;


path::path()
{
	hDirectory = eggDirectory_open("/ape/ImRoBot5/index/bas/k2d/");
	hIndexReader = eggIndexReader_open(hDirectory);
	hIndexSearcher = eggIndexSearcher_new(hIndexReader);
}

path::~path()
{
	eggIndexSearcher_delete(hIndexSearcher);
	eggIndexReader_close(hIndexReader);
	eggDirectory_close(hDirectory);
}

HEGGINDEXREADER path::get_search()
{
	return hIndexSearcher;
}

HEGGINDEXREADER path::get_reader()
{
	return hIndexReader;
}
