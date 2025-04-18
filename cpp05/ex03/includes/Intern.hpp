#ifndef INTERN_HPP
# define INTERN_HPP
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"


class Intern
{
public:
	Intern();
	Intern(const Intern &copy);
	Intern &operator=(const Intern &assign);
	~Intern();

	AForm *makeForm(std::string formName, std::string target);

	class FormNotFoundException : public std::exception
	{
	private:
		std::string _msg;
	public:
		FormNotFoundException(std::string formName);
		virtual ~FormNotFoundException() throw();
		virtual const char *what() const throw();
	};
};


#endif