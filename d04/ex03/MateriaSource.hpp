#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#define MSIZE 4

class MateriaSource : public IMateriaSource
{
	AMateria	*materia[MSIZE];
public:
	~MateriaSource();
	MateriaSource();
	MateriaSource(MateriaSource const & other);
	MateriaSource const & operator=(MateriaSource const & other);

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif
