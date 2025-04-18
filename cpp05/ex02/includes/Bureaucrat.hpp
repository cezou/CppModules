#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include "../../Utils.hpp"
#include "AForm.hpp"

class AForm;

bool isTooHigh(int grade);
bool isTooLow(int grade);

/**
 * @brief Bureaucrat class for handling grades and forms
 */
class Bureaucrat {
public:
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &src);
    ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &rhs);

    const std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signAForm(AForm &aForm) const;
    void executeForm(const AForm &form) const;

    class GradeTooHighException : public std::exception {
    private:
        std::string _msg;
    public:
        GradeTooHighException(const std::string &name);
        virtual ~GradeTooHighException() throw();
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    private:
        std::string _msg;
    public:
        GradeTooLowException(const std::string &name);
        virtual ~GradeTooLowException() throw();
        virtual const char *what() const throw();
    };

private:
    const std::string _name;
    int _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif

