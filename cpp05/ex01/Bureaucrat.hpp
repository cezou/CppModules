#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include "../Utils.hpp"
# include "Form.hpp"

class Form;

bool is_too_high(int grade);
bool is_too_low(int grade);

class Bureaucrat
{
public:
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat const &rhs);

	std::string const	getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
	void				signForm(Form &form) const;

	class GradeTooHighException : public std::exception
	{
	private:
		std::string _msg;
	public:
		GradeTooHighException(const std::string& name);
		virtual ~GradeTooHighException() throw();
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	private:
		std::string _msg;
	public:
		GradeTooLowException(const std::string& name);
		virtual ~GradeTooLowException() throw();
		virtual const char* what() const throw();
	};

private:
	std::string const	_name;
	int					_grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif

