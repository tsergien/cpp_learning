#ifndef SHIFT_HPP
#define SHIFT_HPP
#include "Instruction.hpp"

class Rshift: public virtual Instruction
{
public:
	Rshift();
	~Rshift();
	Rshift(Rshift const & other);
	Rshift & operator=(Rshift const & other);
	
	void	execute(unsigned int *count, char (&cpu)[30000]);
};

#endif