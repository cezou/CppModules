#include "../includes/RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm(target, 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}



void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!getIs_signed())
		throw std::runtime_error(NOT_SIGNED);
	if (executor.getGrade() > getRequired_to_execute())
		throw AForm::GradeTooLowException();
	std::cout << YELLOW << "* Drilling noises * " << RESET << std::endl;
	std::srand(std::time(0) + reinterpret_cast<long>(this));
	if (std::rand() % 2)
		std::cout << GREEN << _target << " has been robotomized successfully!" << RESET << std::endl;
	else
		std::cout << RED << _target << " robotomy failed!" << RESET << std::endl;
}