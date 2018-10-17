#include "includes/Incr.hpp"

Incr::Incr(){}
Incr::~Incr(){}
Incr::Incr(Incr const & other){*this = other;}
Incr & Incr::operator=(Incr const & other){
	(void)other;
	return *this;
}

void	Incr::execute(int *count, char (&cpu)[30000])
{
	cpu[*count]++;
}