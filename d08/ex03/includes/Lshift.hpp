#ifndef LSHIFT_HPP
#define LSHIFT_HPP
#include "Instruction.hpp"

class Lshift: public virtual Instruction
{
public:
	Lshift();
	~Lshift();
	Lshift(Lshift const & other);
	Lshift & operator=(Lshift const & other);
	
	void	execute(unsigned int *count, char (&cpu)[30000]);
};

#endif