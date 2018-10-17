#ifndef DOT_HPP
#define DOT_HPP
#include "Instruction.hpp"

class Dot: public virtual Instruction
{
public:
	Dot();
	~Dot();
	Dot(Dot const & other);
	Dot & operator=(Dot const & other);
	
	void	execute(unsigned int *count, char (&cpu)[30000]);
};

#endif
