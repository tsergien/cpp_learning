#include "includes/Lshift.hpp"

Lshift::Lshift(){}
Lshift::~Lshift(){}
Lshift::Lshift(Lshift const & other){*this = other;}
Lshift & Lshift::operator=(Lshift const & other){
	(void)other;
	return *this;
}

void	Lshift::execute(int *count, char (&cpu)[30000])
{
	// (void)q;
	(void)cpu;
	(*count)--;
}