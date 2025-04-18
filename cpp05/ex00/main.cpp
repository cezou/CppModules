#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	try {
		Bureaucrat b("Super nul", 151);
	} catch (const std::exception &e) {
		std::cout << RED << "[ERR] Exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat b("Super fort", 0);
	} catch (const std::exception &e) {
		std::cout << RED << "[ERR] Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Squid", 5);
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		while (1) {
			b.incrementGrade();
			std::cout << b << std::endl;
		}
	} catch (const std::exception &e) {
		std::cout << RED << "[ERR] Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b("Game", 145);
		while (1)
		{
			std::cout << b << std::endl;
			b.decrementGrade();
		}
	} catch (const std::exception &e) {
		std::cout << RED << "[ERR] Exception: " B << e.what() << R << std::endl;
	}

}