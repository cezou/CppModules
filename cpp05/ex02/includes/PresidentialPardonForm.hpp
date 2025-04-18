/**
 * @file PresidentialPardonForm.hpp
 * @brief Declaration of PresidentialPardonForm class
 */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();

    void execute(Bureaucrat const &executor) const;

private:
    std::string _target;
};

#endif
