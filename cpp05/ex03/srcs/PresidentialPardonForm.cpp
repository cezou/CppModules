#include "../includes/PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm(target, 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!getIs_signed())
		throw std::runtime_error(NOT_SIGNED);
	if (executor.getGrade() > getRequired_to_execute())
		throw AForm::GradeTooLowException();
	std::cout << CYAN << _target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}