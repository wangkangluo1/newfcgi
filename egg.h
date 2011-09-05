#ifndef EGG_H_
#define EGG_H_
#include "config.h"
#include "input.h"

class egg
{
 public:
	egg(path *egg_path, input *inputs);
	virtual ~egg();
	std::string *get_result();
 private:
	input *input_strs;
	path  *paths;
};
#endif
