#include "Bureaucrat.hpp"

bool is_too_high(int grade)
{
	return grade < 1;
}

bool is_too_low(int grade)
{
	return grade > 150;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
	if (is_too_high(grade))
		throw Bureaucrat::GradeTooHighException(_name);
	if (is_too_low(grade))
		throw Bureaucrat::GradeTooLowException(_name);
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
	if (this != &rhs) {
		_grade = rhs._grade;
	}
	return *this;
}

//operator << overload
std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	int grade;

	os << B CYAN << b.getName() << R ", bureaucrat grade " ;
	grade = b.getGrade();
	if (grade < 75)
		os << GREEN;
	else
		os << ORANGE;
	os << b.getGrade() << R ".";
	return os;
}



std::string const Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (is_too_high(_grade - 1))
		throw Bureaucrat::GradeTooHighException(_name);
	--_grade;
}

void Bureaucrat::decrementGrade()
{
	if (is_too_low(_grade + 1))
		throw Bureaucrat::GradeTooLowException(_name);
	++_grade;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& name)
	: _msg(R B CYAN + name + R RED + " : Grade too high") {}
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return _msg.c_str();
}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}


Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& name)
	: _msg(R B CYAN + name + R RED + " : Grade too low") {}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return _msg.c_str();
}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
