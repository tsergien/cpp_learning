#include "AMateria.hpp"

AMateria::AMateria(){}
AMateria::AMateria(std::string const & type): type_(type), xp_(0) {}

AMateria::AMateria(AMateria const & other)
{
	*this = other;
}
AMateria const & AMateria::operator=(AMateria const & other)
{
	xp_ = other.getXP();
	return *this;
}

std::string const & AMateria::getType() const{return type_;}

unsigned int AMateria::getXP() const{return xp_;}

void AMateria::use(ICharacter& target)
{
	type_ += 10;
}

void	AMateria::setXP(unsigned int xp){xp_ = xp;}
