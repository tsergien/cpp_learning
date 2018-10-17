#include "Cure.hpp"

Cure::Cure(): AMateria("Cure"){}
Cure::Cure(Cure const & other){
	*this = other;
}
Cure const & Cure::operator=(Cure const & other){
	setXP(other.getXP());
	return *this;
}
Cure::~Cure(){}

Cure* Cure::clone() const{
	Cure * r = new Cure;
	r->setXP(this->getXP());
	return r;
}
void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() <<  "’s wounds\n";
}