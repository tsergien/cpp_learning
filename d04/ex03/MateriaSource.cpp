#include "MateriaSource.hpp"

MateriaSource::~MateriaSource(){
	for (int i = 0 ;i < MSIZE; i++)
		delete materia[i];
}
MateriaSource::MateriaSource(){}
MateriaSource::MateriaSource(MateriaSource const & other){
	*this = other;
}
MateriaSource const & MateriaSource::operator=(MateriaSource const & other){
	for (int i = 0 ;i < MSIZE; i++)
		delete materia[i];
	int j = 0;
	while (j < MSIZE && other.materia[j] != NULL)
		materia[j] = other.materia[j];
	return *this;
}

void MateriaSource::learnMateria(AMateria* m){
	for (int i = 0 ; i < MSIZE; i++)
		if (materia[i] == NULL)
			materia[i] = m;
}
AMateria* MateriaSource::createMateria(std::string const & type){
	if (materia[0] == 0)
		return 0;
	for (int i = 0; i < MSIZE - 1; i++)
		if (materia[i + 1] == NULL)
		{
			AMateria *r = new *AMateria(type);
			return r;
		}
}