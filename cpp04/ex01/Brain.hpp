#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cctype>
#include <cmath>

class Brain
{
public:
	Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	void setIdea(int index, const std::string &idea);
	std::string getIdea(int index) const;

protected:
	std::string _ideas[100];
};

#endif