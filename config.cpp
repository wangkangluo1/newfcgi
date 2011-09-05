#include "config.h"
#include	<cstdlib>
#include	<fstream>
#include	<iomanip>   
#include	<iostream>  
using namespace std;

global G;

void con_::init()
{
	G.hDirectory = eggDirectory_open("/ape/ImRoBot5/index/bas/k2d/");
	G.hIndexReader = eggIndexReader_open(G.hDirectory);
	G.hIndexSearcher = eggIndexSearcher_new(G.hIndexReader);
}

void con_::end()
{
	eggIndexSearcher_delete(G.hIndexSearcher);
	eggIndexReader_close(G.hIndexReader);
	eggDirectory_close(G.hDirectory);
}
