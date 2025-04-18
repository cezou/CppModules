#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	try {
		Form f("Impossible", 0, 10);
	} catch (const std::exception &e) {
		std::cout << RED << "[ERR] Exception (Form): " << e.what() << std::endl;
	}
	try {
		Form f("Impossible", 10, 151);
	} catch (const std::exception &e) {
		std::cout << RED << "[ERR] Exception (Form): " << e.what() << std::endl;
	}

	{
		Form f("Form", 10, 20);
		Bureaucrat b("Squid Fort", 5);
		std::cout << f << std::endl;
		std::cout << b << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	}

	{
		Form f("Form", 10, 20);
		Bureaucrat b("Squid Nul", 15);
		std::cout << f << std::endl;
		std::cout << b << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	}
}