#ifndef AForm_HPP
# define AForm_HPP

# include "Bureaucrat.hpp"
# define NOT_SIGNED B RED "Form is not signed yet." R

class Bureaucrat;

class AForm 
{
public:
	AForm();
	AForm(const AForm &copy);
	AForm(const std::string name, bool is_signed, const int required_to_sign, const int required_to_execute);
	AForm(const std::string name, const int required_to_sign, const int required_to_execute);
	virtual ~AForm();
	
	/* Operators */
	AForm & operator=(const AForm &assign);
	
	/* Getters */
	const std::string	getName() const;
	bool				getIs_signed() const;
	int					getRequired_to_sign() const;
	int					getRequired_to_execute() const;
	
	/* Member functions */
	void				beSigned(const Bureaucrat &bureaucrat);
	virtual void		execute(Bureaucrat const &executor) const = 0;

	/* Exceptions */
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	
private:
	const std::string	_name;
	const int			_required_to_sign;
	const int			_required_to_execute;
	bool				_is_signed;
	
};

// Stream operators
std::ostream & operator<<(std::ostream &os, const AForm &object);

#endif