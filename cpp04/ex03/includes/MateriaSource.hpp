#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "Utils.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_templates[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &copy);
	virtual ~MateriaSource();

	MateriaSource &operator=(const MateriaSource &assign);

	virtual void learnMateria(AMateria *m);
	virtual AMateria *createMateria(std::string const &type);
};

#endif
