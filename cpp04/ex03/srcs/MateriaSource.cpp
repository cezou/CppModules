#include "MateriaSource.hpp"

/**
 * @brief Default constructor for MateriaSource
 */
MateriaSource::MateriaSource()
{
	DEBUG_PRINT(GREEN << "Default Constructor called of MateriaSource" << R << std::endl);
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
}

/**
 * @brief Copy constructor for MateriaSource
 * @param copy The MateriaSource to copy
 */
MateriaSource::MateriaSource(const MateriaSource &copy)
{
	DEBUG_PRINT(GREEN << "Copy Constructor called of MateriaSource" << R << std::endl);
	for (int i = 0; i < 4; i++)
	{
		if (copy._templates[i])
			_templates[i] = copy._templates[i]->clone();
		else
			_templates[i] = NULL;
	}
}

/**
 * @brief Destructor for MateriaSource
 */
MateriaSource::~MateriaSource()
{
	DEBUG_PRINT(RED << "Destructor called of MateriaSource" << R << std::endl);
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i])
			delete _templates[i];
	}
}

/**
 * @brief Assignment operator for MateriaSource
 * @param assign The MateriaSource to assign from
 * @return Reference to the assigned MateriaSource
 */
MateriaSource &MateriaSource::operator=(const MateriaSource &assign)
{
	if (this != &assign)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_templates[i])
				delete _templates[i];
			_templates[i] = NULL;
		}
		for (int i = 0; i < 4; i++)
		{
			if (assign._templates[i])
				_templates[i] = assign._templates[i]->clone();
		}
	}
	return *this;
}

/**
 * @brief Learn a new materia to create later
 * @param m The materia to learn
 */
void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		DEBUG_PRINT("MateriaSource can't learn NULL materia" << std::endl);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!_templates[i])
		{
			_templates[i] = m;
			DEBUG_PRINT("MateriaSource learned " << m->getType() << std::endl);
			return;
		}
	}
	DEBUG_PRINT("MateriaSource can't learn more materia" << std::endl);
	delete m;
}

/**
 * @brief Create a new materia based on type
 * @param type The type of materia to create
 * @return Pointer to the newly created materia, or NULL if type unknown
 */
AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] && _templates[i]->getType() == type)
			return _templates[i]->clone();
	}
	DEBUG_PRINT("MateriaSource doesn't know type: " << type << std::endl);
	return NULL;
}
