#include "Ice.hpp"

Ice::Ice(): AMateria("ice"){}
Ice::Ice(Ice const & other){
	*this = other;
}
Ice const & Ice::operator=(Ice const & other){
	setXP(other.getXP());
	return *this;
}
Ice::~Ice(){}

Ice* Ice::clone() const{
	Ice * r = new Ice;
	r->setXP(this->getXP());
	return r;
}
void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at " << target.getName() <<  " *\n";
}