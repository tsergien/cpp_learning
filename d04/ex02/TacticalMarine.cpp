#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine(){
	std::cout << "Tactical Marine ready for battle\n";
}
TacticalMarine::~TacticalMarine(){
	std::cout << "Aaargh ...\n";
}
TacticalMarine::TacticalMarine(TacticalMarine const & other){
	*this = other;
}
TacticalMarine const & TacticalMarine::operator=(TacticalMarine const & other){
	(void)other;
	return *this;
}

TacticalMarine* TacticalMarine::clone() const{
	TacticalMarine * res = new TacticalMarine;
	return res;
}

void TacticalMarine::battleCry() const{
	std::cout << "For the holy PLOT !\n";
}
void TacticalMarine::rangedAttack() const{
	std::cout << "* attacks with bolter *\n";
}
void TacticalMarine::meleeAttack() const{
	std::cout << "* attacks with chainsword *\n";
}
