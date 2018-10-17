#ifndef DECR_HPP
#define DECR_HPP
#include "Instruction.hpp"

class Decr: public virtual Instruction
{
public:
	Decr();
	~Decr();
	Decr(Decr const & other);
	Decr & operator=(Decr const & other);
	
	void	execute(unsigned int *count, char (&cpu)[30000]);
};

#endif
