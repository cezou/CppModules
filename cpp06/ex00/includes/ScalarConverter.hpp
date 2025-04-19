#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "../../Utils.hpp"
/**
 * @brief Converts scalar string literals to their actual types and displays them.
 *
 * This class provides a static method to parse a string representation of a
 * char, int, float, or double, convert it, and display the result in all four types.
 * It handles special values like NaN and infinity. The class itself is non-instantiable.
 */
class ScalarConverter
{
public:
	virtual ~ScalarConverter();
	
	static void convert(const std::string &input);
	
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter & operator=(const ScalarConverter &assign);

};

#endif