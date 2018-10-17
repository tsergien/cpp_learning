#ifndef COME_HPP
#define COME_HPP
#include "Instruction.hpp"

class Coma: public virtual Instruction
{
public:
	Coma();
	~Coma();
	Coma(Coma const & other);
	Coma & operator=(Coma const & other);
	
	void	execute(unsigned int *count, char (&cpu)[30000]);
};

#endif
