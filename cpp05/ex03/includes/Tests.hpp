#ifndef TESTS_HPP
#define TESTS_HPP

#include "Intern.hpp"

void fail_makeForm(Intern& intern, AForm*& form)
{
	deleteAndNull(form);
	form = intern.makeForm("squid game", "Squidodo"); 
	std::cout << *form << std::endl;
}

void fail_BureaucratGradeTooHigh(void)
{
	Bureaucrat bureaucrat("Bureaucrat", 0);
}

void fail_BureaucratGradeTooLow(void)
{
	Bureaucrat bureaucrat("Bureaucrat", 151);
}

void fail_incrementGrade(void)
{
	Bureaucrat bureaucrat("Bureaucrat", 1);
	bureaucrat.incrementGrade();
}

void fail_decrementGrade(void)
{
	Bureaucrat bureaucrat("Bureaucrat", 150);
	bureaucrat.decrementGrade();
}

void fail_signForm(AForm*& form)
{
	Bureaucrat bureaucrat("Bureaucrat", 73); // Grade too low for Robotomy (72)
	form->beSigned(bureaucrat); // This should throw GradeTooLowException
}

void fail_execForm(AForm*& form)
{
	Bureaucrat bureaucrat("Bureaucrat", 72); // Grade too low for executing Robotomy (45)
	form->beSigned(bureaucrat);
	form->execute(bureaucrat);
}

void fail_executeNotSigned(Intern& intern, AForm*& form)
{
	deleteAndNull(form);
	form = intern.makeForm("presidential pardon", "Trump j'ai perdu tout mon ether");
	Bureaucrat bureaucrat("Bureaucrat", 1); 
	form->execute(bureaucrat); // Should throw a standard exception
}

void fail_executeImpossibleFile(Intern& intern, AForm*& form)
{
	deleteAndNull(form);
	form = intern.makeForm("shrubbery creation", "Impossible");
	Bureaucrat bureaucrat("Bureaucrat", 1);
	form->beSigned(bureaucrat);
	form->execute(bureaucrat); // Should throw an exception during file creation
}

#endif