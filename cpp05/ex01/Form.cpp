#include "Form.hpp"

// Constructors
Form::Form() : 
	_name("default"), 
	_required_to_sign(1), 
	_required_to_execute(1),
	_is_signed(false)
{}

Form::Form(const Form &copy) : 
	_name(copy.getName()), 
	_required_to_sign(copy.getRequired_to_sign()), 
	_required_to_execute(copy.getRequired_to_execute()),
	_is_signed(copy.getIs_signed())
{}

Form::Form(const std::string name, bool is_signed, const int required_to_sign, const int required_to_execute) : 
	_name(name), 
	_required_to_sign(required_to_sign), 
	_required_to_execute(required_to_execute),
	_is_signed(is_signed)
{}

Form::Form(const std::string name, const int required_to_sign, const int required_to_execute) : 
	_name(name), 
	_required_to_sign(required_to_sign), 
	_required_to_execute(required_to_execute),
	_is_signed(0)
{}


Form::~Form()
{
}


Form & Form::operator=(const Form &assign)
{
	if (this != &assign)
		_is_signed = assign.getIs_signed();
	return *this;
}


// Getters / Setters
const std::string Form::getName() const
{
	return _name;
}
bool Form::getIs_signed() const
{
	return _is_signed;
}
int Form::getRequired_to_sign() const
{
	return _required_to_sign;
}
int Form::getRequired_to_execute() const
{
	return _required_to_execute;
}


// Exceptions
const char * Form::GradeTooLowException::what() const throw()
{
	return B RED "Bureaucrat's grade is too low" R;
}
const char * Form::GradeTooHighException::what() const throw()
{
	return B RED "Grade too high" R;
}


// Stream operators
// Print Form name, is_signed, required_to_sign, and required_to_execute
std::ostream & operator<<(std::ostream &os, const Form &object)
{
	os << std::endl << "Form's name: " B BLUE << object.getName() << R << std::endl;
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
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _required_to_sign)
		throw Form::GradeTooLowException();
	_is_signed = true;
}