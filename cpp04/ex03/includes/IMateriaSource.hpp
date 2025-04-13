#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP
#include <iostream>
#include <string>
#include "AMateria.hpp"


/**
 * @brief The IMateriaSource interface
 * 
 * This interface defines the MateriaSource class, which is responsible for
 * creating and learning new Materia types. It provides two pure virtual
 * functions: learnMateria and createMateria.
 */
class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif