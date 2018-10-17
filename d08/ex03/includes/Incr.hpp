#ifndef INCR_HPP
#define INCR_HPP
#include "Instruction.hpp"

class Incr: public virtual Instruction
{
public:
	Incr();
	~Incr();
	Incr(Incr const & other);
	Incr & operator=(Incr const & other);
	
	void	execute(unsigned int *count, char (&cpu)[30000]);
};

#endif
