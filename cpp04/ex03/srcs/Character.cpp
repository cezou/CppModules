#include "Character.hpp"

/**
 * @brief Default constructor for Character
 */
Character::Character() : _name("Default"), _floor_count(0)
{
	DEBUG_PRINT(GREEN << "Default Constructor called of Character" << R << std::endl);
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < MAX_FLOOR; i++)
		_floor[i] = NULL;
}

/**
 * @brief Constructor with name for Character
 * @param name The name of the character
 */
Character::Character(std::string const &name) : _name(name), _floor_count(0)
{
	DEBUG_PRINT(GREEN << "Name Constructor called of Character" << R << std::endl);
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < MAX_FLOOR; i++)
		_floor[i] = NULL;
}

/**
 * @brief Copy constructor for Character
 * @param copy The Character to copy
 */
Character::Character(const Character &copy) : _name(copy._name), _floor_count(0)
{
	DEBUG_PRINT(GREEN << "Copy Constructor called of Character" << R << std::endl);
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
			_inventory[i] = copy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	for (int i = 0; i < MAX_FLOOR; i++)
		_floor[i] = NULL;
}

/**
 * @brief Destructor for Character
 */
Character::~Character()
{
	DEBUG_PRINT(RED << "Destructor called of Character" << R << std::endl);
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	cleanFloor();
}

/**
 * @brief Assignment operator for Character
 * @param assign The Character to assign from
 * @return Reference to the assigned Character
 */
Character &Character::operator=(const Character &assign)
{
	if (this != &assign)
	{
		_name = assign._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (assign._inventory[i])
				_inventory[i] = assign._inventory[i]->clone();
		}
		cleanFloor();
	}
	return *this;
}

/**
 * @brief Get the name of the Character
 * @return The name as a const reference to a string
 */
std::string const &Character::getName() const
{
	return _name;
}

/**
 * @brief Equip a materia to the character's inventory
 * @param m The materia to equip
 */
void Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			DEBUG_PRINT(_name << " equipped " << m->getType() << " at slot " << i << std::endl);
			return;
		}
	}
	DEBUG_PRINT(_name << " has no free slots to equip " << m->getType() << std::endl);
	if (_floor_count < MAX_FLOOR)
		_floor[_floor_count++] = m;
	else
	{
		DEBUG_PRINT("WARNING: Floor is full! can't equip.." << std::endl);
		delete m;
	}
}

/**
 * @brief Unequip a materia from the character's inventory
 * @param idx Index of the inventory slot to unequip
 */
void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
	{
		DEBUG_PRINT(_name << " unequipped " << _inventory[idx]->getType() << " from slot " << idx << std::endl);
		if (_floor_count < MAX_FLOOR)
		{
			_floor[_floor_count++] = _inventory[idx];
			_inventory[idx] = NULL;
		}
		else
			DEBUG_PRINT("WARNING: Floor is full! can't unequip.." << std::endl);
	}
}

/**
 * @brief Use a materia from the character's inventory
 * @param idx Index of the inventory slot to use
 * @param target Character to use the materia on
 */
void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
	{
		DEBUG_PRINT(_name << " has only 4 slots [0:3]" << idx << std::endl);
		return;
	}
	if (_inventory[idx])
		_inventory[idx]->use(target);
	else
		DEBUG_PRINT(_name << " has nothing to use at slot " << idx << std::endl);
}

/**
 * @brief Use all materias in the character's inventory
 * @param target Character to use the materias on
 */
void Character::useAll(ICharacter &target)
{
	DEBUG_PRINT(_name << " is using all equipped materias on " << target.getName() << std::endl);
	for (int i = 0; i < 4; i++)
		this->use(i, target);
}

/**
 * @brief Clean up materias dropped on the floor
 */
void Character::cleanFloor()
{
	for (int i = 0; i < _floor_count; i++)
	{
		if (_floor[i])
		{
			DEBUG_PRINT("Cleaning " << _floor[i]->getType() << " from floor" << std::endl);
			delete _floor[i];
			_floor[i] = NULL;
		}
	}
	_floor_count = 0;
}
