#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(target, 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!getIs_signed())
		throw std::runtime_error(NOT_SIGNED);
	if (executor.getGrade() > getRequired_to_execute())
		throw AForm::GradeTooLowException();

	std::string tree =
		"    .-\"\"\"-.   \n"
		"   (       )  \n"
		"  (         ) \n"
		"  (         ) \n"
		"   (       )  \n"
		".___`-._.-'_.__.\n";

	std::ofstream ofs((_target + "_shrubbery").c_str());
	if (!ofs)
		throw std::runtime_error(B RED "Failed to create shrubbery file" R);
	ofs << tree;
	std::cout << GREEN << "Shrubbery created at '" << _target << "_shrubbery'!" << RESET << std::endl;
}