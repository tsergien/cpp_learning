#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator(){
	std::cout << "* teleports from space *\n";
}
AssaultTerminator::~AssaultTerminator(){
	std::cout << "I’ll be back ...\n";
}
AssaultTerminator::AssaultTerminator(AssaultTerminator const & other){
	*this = other;
}
AssaultTerminator const & AssaultTerminator::operator=(AssaultTerminator const & other){
	(void)other;
	return *this;
}

AssaultTerminator* AssaultTerminator::clone() const{
	AssaultTerminator * res = new AssaultTerminator;
	return res;
}

void AssaultTerminator::battleCry() const{
	std::cout << "This code is unclean. PURIFY IT !\n";
}
void AssaultTerminator::rangedAttack() const{
	std::cout << "* does nothing *\n";
}
void AssaultTerminator::meleeAttack() const{
	std::cout << "* attacks with chainfists *\n";
}