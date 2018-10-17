#include "includes/Rshift.hpp"

Rshift::Rshift(): Instruction(){}
Rshift::~Rshift(){}
Rshift::Rshift(Rshift const & other){*this = other;}
Rshift & Rshift::operator=(Rshift const & other){
	(void)other;
	return *this;
}

void	Rshift::execute(int *count, char (&cpu)[30000])
{
	(void)cpu;
	(*count)++;
}