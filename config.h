#ifndef CONFIG_H_
#define CONFIG_H_
#include "input.h"


extern "C"
{
	
#include <egg2/Egg2.h>
#include <scholar/ImLexAnalyzer.h>
#include <scholar/ImTokenList.h>
#include <scholar/ImCnLexAnalyzer.h>
#include <scholar/ImCwsLexAnalyzer.h>
}

class con_
{
 public:
	void init();
	void end();
};


typedef struct global_ global;

struct global_
{
	HEGGDIRECTORY hDirectory;
	HEGGINDEXREADER hIndexReader;
	HEGGINDEXSEARCHER hIndexSearcher;
	input inputs;
	con_ con;
};


#endif /* CONFIG_H_ */
