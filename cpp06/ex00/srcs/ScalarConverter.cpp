#include "../includes/ScalarConverter.hpp"
#include "../../Utils.hpp"
#include <sstream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cerrno>

// Constructors
ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void) copy;
}

// Destructor
ScalarConverter::~ScalarConverter()
{
}

// Operators
ScalarConverter & ScalarConverter::operator=(const ScalarConverter &assign)
{
	(void) assign;
	return *this;
}

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNDEFINED
};

/**
 * @brief Determines the type of the input string.
 * @param input The input string literal.
 * @return The detected type (CHAR, INT, FLOAT, DOUBLE, UNDEFINED).
 */
int findType(const std::string &input)
{
	if (input.length() == 1 && !std::isdigit(input[0]))
		return CHAR;
	if (input == "nanf" || input == "+inff" || input == "-inff")
		return FLOAT;
	if (input == "nan" || input == "+inf" || input == "-inf")
		return DOUBLE;

	bool hasDecimal = false;
	for (size_t i = 0; i < input.length(); ++i)
		if (input[i] == '.')
			hasDecimal = true;

	if (hasDecimal) 
	{
		if (!input.empty() && input[input.length() - 1] == 'f')
			return FLOAT;
		else
			return DOUBLE;
	}

	size_t start = 0;
	if (input[0] == '+' || input[0] == '-')
		start = 1;
	if (start >= input.length())
		return UNDEFINED;

	for (size_t i = start; i < input.length(); ++i)
	{
		if (!std::isdigit(input[i]))
			return UNDEFINED;
	}
	return INT;
}

static void printChar(double d)
{
	std::cout << "char: ";
	if (std::isnan(d) || std::isinf(d) || d < 0)
		std::cout << "impossible" << std::endl;
	else
	{
		char c = static_cast<char>(d);
		if (std::isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
}

static void printInt(double d)
{
	std::cout << "int: ";
	if (std::isnan(d) || std::isinf(d) 
			|| d < static_cast<double>(std::numeric_limits<int>::min())
			|| d > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
}

static void printFloat(double d)
{
	std::cout << "float: ";
	float f = static_cast<float>(d);

	if (std::isnan(d))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(d)) 
		std::cout << (d > 0 ? "+inff" : "-inff") << std::endl;
	else if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

static void printDouble(double d)
{
	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan" << std::endl;
	else if (std::isinf(d))
		std::cout << (d > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}

/**
 * @brief Sets the double value based on input string and type, checking validity.
 * @param input The input string literal.
 * @param type The detected type (INT, FLOAT, DOUBLE).
 * @param d_val Reference to the double value to be set.
 * @param possible Reference to the boolean indicating if conversion is possible.
 */
static void setVal(const std::string &input, int type, double &d_val, bool &possible)
{
	if (input == "nan" || input == "nanf")
		d_val = std::numeric_limits<double>::quiet_NaN();
	else if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
		d_val = std::numeric_limits<double>::infinity();
	else if (input == "-inf" || input == "-inff")
		d_val = -std::numeric_limits<double>::infinity();
	else
	{
		char *endptr = NULL;
		errno = 0;
		d_val = std::strtod(input.c_str(), &endptr);
		if (errno == ERANGE
				||  endptr == input.c_str()
				|| (*endptr && !(type == FLOAT && *endptr == 'f' && !*(endptr + 1))))
			possible = false;
	}
}

static void printImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}


/**
 * @brief Converts the input string to its detected type and prints all four representations.
 * 
 * This function first determines the type of the input string (char, int, float, double),
 * then converts it to the corresponding value, and prints the results in all four formats.
 * It handles special cases like NaN and infinity, and checks for valid conversions.
 * If the conversion is not possible, it prints "impossible" for all types.
 */
void ScalarConverter::convert(const std::string &input)
{
	if (input.empty())
		return (v("Error: Empty input"));

	bool possible = true;
	double d_val = 0.0;

	int type = findType(input);
	if (type == UNDEFINED)
		possible = false;
	else if (type == CHAR)
		d_val = static_cast<double>(input[0]);
	else
		setVal(input, type, d_val, possible);

	if (!possible)
		return printImpossible();

	printChar(d_val);
	printInt(d_val);
	printFloat(d_val);
	printDouble(d_val);
}

