#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form();
	Form(const Form &copy);
	Form(const std::string name, bool is_signed, const int required_to_sign, const int required_to_execute);
	Form(const std::string name, const int required_to_sign, const int required_to_execute);
	~Form();
	
	/* Operators */
	Form & operator=(const Form &assign);
	
	/* Getters */
	const std::string	getName() const;
	bool				getIs_signed() const;
	int					getRequired_to_sign() const;
	int					getRequired_to_execute() const;
	
	/* Member functions */
	void				beSigned(const Bureaucrat &bureaucrat);

	/* Exceptions */
	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw();
	};
	
private:
	const std::string	_name;
	const int			_required_to_sign;
	const int			_required_to_execute;
	bool				_is_signed;
	
};

// Stream operators
std::ostream & operator<<(std::ostream &os, const Form &object);

#endif