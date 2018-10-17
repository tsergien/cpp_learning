#include "includes/Decr.hpp"

Decr::Decr(){}
Decr::~Decr(){}
Decr::Decr(Decr const & other){*this = other;}
Decr & Decr::operator=(Decr const & other){
	(void)other;
	return *this;
}

void	Decr::execute(int *count, char (&cpu)[30000])
{
	// (void)q;
	cpu[*count]--;
}