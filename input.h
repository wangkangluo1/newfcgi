#ifndef INPUT_H_
#define INPUT_H_

class input
{
 private:
	char *input_strs;
	
 public:
	void init(char *str);
	char *get(char *search_arg);
};

#endif
