#ifndef OPENBRACKET_HPP
#define OPENBRACKET_HPP
#include "Instruction.hpp"

class OpenBracket: public virtual Instruction
{
public:
	OpenBracket();
	~OpenBracket();
	OpenBracket(OpenBracket const & other);
	OpenBracket & operator=(OpenBracket const & other);
	
	void	execute(unsigned int *count, char (&cpu)[30000]);
};

#endif