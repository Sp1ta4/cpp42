#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << CYAN << "\n=== [Test 1] Valid ShrubberyCreationForm Signing & Execution ===" << RESET << std::endl;
	{
		try
		{
			Bureaucrat bob("Bob", 100);
			ShrubberyCreationForm form("home");

			std::cout << bob << std::endl;
			std::cout << form << std::endl;

			bob.signForm(form);
			bob.executeForm(form); // should create a file
		}
		catch (std::exception &e)
		{
			std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}

	std::cout << CYAN << "\n=== [Test 2] RobotomyRequestForm Random Execution ===" << RESET << std::endl;
	{
		try
		{
			Bureaucrat rob("Rob", 40);
			RobotomyRequestForm form("TargetBot");

			rob.signForm(form);
			for (int i = 0; i < 4; ++i)
				rob.executeForm(form); // ~50% success chance
		}
		catch (std::exception &e)
		{
			std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}

	std::cout << CYAN << "\n=== [Test 3] PresidentialPardonForm Success ===" << RESET << std::endl;
	{
		try
		{
			Bureaucrat president("President", 2);
			PresidentialPardonForm form("Prisoner42");

			president.signForm(form);
			president.executeForm(form);
		}
		catch (std::exception &e)
		{
			std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}

	std::cout << CYAN << "\n=== [Test 4] Execution without signing ===" << RESET << std::endl;
	{
		try
		{
			Bureaucrat tom("Tom", 1);
			ShrubberyCreationForm form("garden");

			tom.executeForm(form); // should throw
		}
		catch (const std::exception &e)
		{
			std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}

	std::cout << CYAN << "\n=== End of tests ===" << RESET << std::endl;
	return 0;
}
