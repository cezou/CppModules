#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
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

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	virtual ~Cat();
	void makeSound() const;

	void setIdea(int index, const std::string &idea);
	std::string getIdea(int index) const;

private:
	Brain *_brain;
};

#endif