#include "Character.hpp"

Character::Character(): name_("Character"){
	for (int i = 0; i < MSIZE; i++)
		materia[i] = 0;
}
Character::Character(std::string name): name_(name){
	for (int i = 0; i < MSIZE; i++)
		materia[i] = 0;
}
Character::Character(Character const & other){
	*this = other;
}
Character const & Character::operator=(Character const & other){
	for (int i = 0; i < MSIZE; i++)
		if (materia[i] != NULL)
			delete materia[i];
	for (int i = 0; i < MSIZE; i++)
		materia[i] = other.materia[i];
	name_ = other.getName();
	return *this;
}
Character::~Character(){
	for (int i = 0; i < MSIZE; i++)
		if (materia[i] != NULL)
			delete materia[i];
}

std::string const & Character::getName() const{return name_;}
void Character::equip(AMateria* m){
	if (materia[MSIZE - 1] != NULL)
		return ;
	for (int i = 0; i < MSIZE; i++)
		if (materia[i] == NULL)
		{
			materia[i] = new *AMateria;
			break ;
		}
}
void Character::unequip(int idx){
	if (materia[0] == NULL || idx < 0 || idx > MSIZE)
		return ;
	materia[idx] = NULL;
	for (int i = 0; i < MSIZE; i++)
		if (materia[i] == NULL  && i + 1 < MSIZE && materia[i+1] != NULL)
		{
			for (int j = i; j < MSIZE - 1; j++)
				materia[j] = materia[j + 1];
		}
}

void Character::use(int idx, Character& target){
	if (idx < 0 || idx > MSIZE || materia[idx] == NULL)
		return ;
	materia[idx]->AMateria::use(target);
}