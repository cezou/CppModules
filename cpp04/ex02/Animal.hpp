#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <cmath>
#define RESET "\x1B[0m"
#define RED "\x1B[1;31m"
#define GREEN "\x1B[1;32m"
#define YELLOW "\x1B[1;33m"
#define BLUE "\x1B[1;34m"
#define MAGENTA "\x1B[1;35m"
#define CYAN "\x1B[1;36m"
#define WHITE "\x1B[1;37m"
#define GRAY "\x1B[1;90m"
#define BOLD_WHITE "\x1B[1;97m"

class Animal
{
public:
	Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal();
	virtual void makeSound() const = 0; // virtuelle pure (la calsse ne peut pas être instanciée directement)
	std::string getType() const;

protected:
	std::string _type;
};

#endif