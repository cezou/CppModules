#include "includes/Intern.hpp"
#include "includes/Tests.hpp"

int main()
{
	AForm* form = NULL;
	Intern someRandomIntern;

	try {
		form = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << "Initial form created: " << *form << std::endl;

		// --- Fail Functions ---
		// Comment  at a time to test specific failures that are gonna be thrown and catched
		fail_makeForm(someRandomIntern, form);
		fail_BureaucratGradeTooHigh();
		fail_BureaucratGradeTooLow();
		fail_incrementGrade();
		fail_decrementGrade();
		fail_signForm(form);
		fail_executeNotSigned(someRandomIntern, form);
		fail_execForm(form);
		fail_executeImpossibleFile(someRandomIntern, form); 

	} catch (const Intern::FormNotFoundException& e) {
		std::cerr << "Intern Error: " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Bureaucrat Error: " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Bureaucrat Error: " << e.what() << std::endl;
	} catch (const AForm::GradeTooHighException& e) {
		std::cerr << "Form Error: " << e.what() << std::endl;
	} catch (const AForm::GradeTooLowException& e) {
		std::cerr << "Form Error: " << e.what() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Standard Exception: " << e.what() << std::endl;
	}
	deleteAndNull(form);
	return 0;
}
