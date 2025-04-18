#include "AForm.hpp"

// Constructors
AForm::AForm() : 
	_name("default"), 
	_required_to_sign(1), 
	_required_to_execute(1),
	_is_signed(false)
{}

AForm::AForm(const AForm &copy) : 
	_name(copy.getName()), 
	_required_to_sign(copy.getRequired_to_sign()), 
	_required_to_execute(copy.getRequired_to_execute()),
	_is_signed(copy.getIs_signed())
{}

AForm::AForm(const std::string name, bool is_signed, const int required_to_sign, const int required_to_execute) : 
	_name(name), 
	_required_to_sign(required_to_sign), 
	_required_to_execute(required_to_execute),
	_is_signed(is_signed)
{}

AForm::AForm(const std::string name, const int required_to_sign, const int required_to_execute) : 
	_name(name), 
	_required_to_sign(required_to_sign), 
	_required_to_execute(required_to_execute),
	_is_signed(0)
{}


AForm::~AForm()
{
}


AForm & AForm::operator=(const AForm &assign)
{
	if (this != &assign)
		_is_signed = assign.getIs_signed();
	return *this;
}


// Getters / Setters
const std::string AForm::getName() const
{
	return _name;
}
bool AForm::getIs_signed() const
{
	return _is_signed;
}
int AForm::getRequired_to_sign() const
{
	return _required_to_sign;
}
int AForm::getRequired_to_execute() const
{
	return _required_to_execute;
}


// Exceptions
const char * AForm::GradeTooLowException::what() const throw()
{
	return B RED "Bureaucrat's grade is too low" R;
}
const char * AForm::GradeTooHighException::what() const throw()
{
	return B RED "Grade too high" R;
}


// Stream operators
// Print AForm name, is_signed, required_to_sign, and required_to_execute
std::ostream & operator<<(std::ostream &os, const AForm &object)
{
	os << std::endl << "AForm's name: " B BLUE << object.getName() << R << std::endl;
	if (object.getIs_signed())
		os <<  PINK " is signed!" R << std::endl;
	else
		os << GREEN " is not signed yet." R << std::endl;
	os << "Required to sign: " R;
	if (object.getRequired_to_sign() < 75)
		os << ORANGE;
	else
		os << GREEN;
	os << B << object.getRequired_to_sign() << R << std::endl;
	os << "Required to execute: ";
	if (object.getRequired_to_execute() < 75)
		os << ORANGE;
	else
		os << GREEN;
	os << B << object.getRequired_to_execute() << R << std::endl;
	return os;
}


// Member functions
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _required_to_sign)
		throw AForm::GradeTooLowException();
	_is_signed = true;
}