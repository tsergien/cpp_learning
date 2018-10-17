#ifndef CLOSEBRACKET_HPP
#define CLOSEBRACKET_HPP
#include "Instruction.hpp"

class CloseBracket: public virtual Instruction
{
public:
	CloseBracket();
	~CloseBracket();
	CloseBracket(CloseBracket const & other);
	CloseBracket & operator=(CloseBracket const & other);
	
	void	execute(unsigned int *count, char (&cpu)[30000]);
};

#endif