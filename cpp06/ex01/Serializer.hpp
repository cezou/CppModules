#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "../Utils.hpp"
# include <stdint.h>

/**
 * @brief A simple data structure for serialization testing.
 */
struct Data
{
	void display() const
	{
		std::cout << B CYAN "Value: " R << value << std::endl;
		std::cout << B BLUE "Text: " R << text << std::endl;
	}
	int			value;
	std::string	text;
};

/**
 * @brief Provides static methods to serialize and deserialize a Data pointer.
 *
 * This class cannot be instantiated. It converts a Data pointer to uintptr_t
 * and back.
 */
class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer(); 
		Serializer(const Serializer &copy); 
		~Serializer();
		Serializer & operator=(const Serializer &assign); 
};

#endif