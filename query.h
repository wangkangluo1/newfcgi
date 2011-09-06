#ifndef QUERY_H_
#define QUERY_H_

#include    "egg.h"


class query
{
 public:
	query();
	virtual ~query();
  	void  add(const char *keywords, std::string key);
	HEGGQUERY	get_query();
 private:
	HEGGQUERY query_str;
};

#endif
