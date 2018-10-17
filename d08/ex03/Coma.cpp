#include "includes/Coma.hpp"
#include <iostream>

Coma::Coma(){}
Coma::~Coma(){}
Coma::Coma(Coma const & other){*this = other;}
Coma & Coma::operator=(Coma const & other){
	(void)other;
	return *this;
}

void	Coma::execute(int *count, char (&cpu)[30000]){
	std::cin >> cpu[*count];
}