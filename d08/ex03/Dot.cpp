#include "includes/Dot.hpp"
#include <iostream>

Dot::Dot(){}
Dot::~Dot(){}
Dot::Dot(Dot const & other){*this = other;}
Dot & Dot::operator=(Dot const & other){
	(void)other;
	return *this;
}

void	Dot::execute(int *count, char (&cpu)[30000])
{
	// (void)q;
	std::cout << cpu[*count];
}