/**
 * @file main.cpp
 * @brief Test for all forms and bureaucrats
 */
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"

int main()
{
    std::cout << B << "--- ShrubberyCreationForm ---" << R << std::endl;
    {
        ShrubberyCreationForm shrub("Squidgame");
        ShrubberyCreationForm impossible("Impossible");
        Bureaucrat boss("MafiaBoss", 1);
        Bureaucrat Lvl1Crook("Lvl1Crook", 140);

		std::cout << B << "-- Executing not signed form --" << R << std::endl;
        boss.executeForm(shrub);
        boss.signAForm(shrub);
        boss.executeForm(shrub);

		std::cout << B << "-- File w/out rights --" << R << std::endl;
		boss.signAForm(impossible);
		boss.executeForm(impossible);
		std::cout << B << "-- Not a good grade until.. --" << R << std::endl;
		while (Lvl1Crook.getGrade() > shrub.getRequired_to_execute()) 
		{
			Lvl1Crook.incrementGrade();
			Lvl1Crook.executeForm(shrub);
		}
   	}
    std::cout << B << "\n--- RobotomyRequestForm ---" << R << std::endl;
    {
        RobotomyRequestForm robo("Bender");
        Bureaucrat robot("Robot", 1);
        Bureaucrat intern("Intern", 100);
        robot.signAForm(robo);
        robot.executeForm(robo);
        intern.executeForm(robo);
    }

    std::cout << B << "\n--- PresidentialPardonForm ---" << R << std::endl;
    {
        PresidentialPardonForm pardon("Un mec sincèrement désolé");
        Bureaucrat pres("President", 1);
        Bureaucrat citizen("Citizen", 30);
        pres.signAForm(pardon);
        pres.executeForm(pardon);
        citizen.executeForm(pardon);
    }

    std::cout << B << "\n--- Test non signé ---" << R << std::endl;
    {
        ShrubberyCreationForm shrub("Squidgame");
        Bureaucrat boss("Boss", 1);
        boss.executeForm(shrub);
    }
}
