#ifndef CONFIG_H_
#define CONFIG_H_

extern "C"
{
	
#include <egg2/Egg2.h>
#include <scholar/ImLexAnalyzer.h>
#include <scholar/ImTokenList.h>
#include <scholar/ImCnLexAnalyzer.h>
#include <scholar/ImCwsLexAnalyzer.h>
}

class path
{
	
 public:
	path();
	virtual ~path();
	HEGGINDEXREADER get_search();
	HEGGINDEXREADER get_reader();
 private:
	HEGGDIRECTORY hDirectory;
	HEGGINDEXREADER hIndexReader;
	HEGGINDEXSEARCHER hIndexSearcher;
};


#endif /* CONFIG_H_ */
