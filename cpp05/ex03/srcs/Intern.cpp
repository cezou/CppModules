#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &copy) {
	(void)copy;
}
Intern &Intern::operator=(const Intern &assign) {
	(void)assign;
	return *this;
}
Intern::~Intern() {}

AForm *Intern::makeForm(std::string formName, std::string target) {
	AForm *form = NULL;

	if (formName == "robotomy request")
		form = new RobotomyRequestForm(target);
	else if (formName == "shrubbery creation")
		form = new ShrubberyCreationForm(target);
	else if (formName == "presidential pardon")
		form = new PresidentialPardonForm(target);
	else
		throw FormNotFoundException(formName);
	std::cout << "Intern creates " B BLUE << formName << R << std::endl;
	return form;
}




Intern::FormNotFoundException::FormNotFoundException(std::string formName) :
	_msg(R B BLUE + formName + R RED + " : Form not found" R) {}
const char *Intern::FormNotFoundException::what() const throw() {
	return _msg.c_str();
}

Intern::FormNotFoundException::~FormNotFoundException() throw() {}
