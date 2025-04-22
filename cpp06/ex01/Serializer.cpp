#include "Serializer.hpp"

// Private Constructor
Serializer::Serializer()
{
}

// Private Copy Constructor
Serializer::Serializer(const Serializer &copy)
{
	(void) copy;
}

// Private Destructor
Serializer::~Serializer()
{
}

// Private Assignment Operator
Serializer & Serializer::operator=(const Serializer &assign)
{
	// Non-instantiable
	(void) assign;
	return *this;
}

/**
 * @brief Converts a Data pointer to an unsigned integer type.
 * @param ptr Pointer to the Data object.
 * @return The unsigned integer representation of the pointer.
 */
uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

/**
 * @brief Converts an unsigned integer type back to a Data pointer.
 * @param raw The unsigned integer representation.
 * @return Pointer to Data.
 */
Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

