#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << CYAN << "\n=== [Test 1] Intern creates valid forms ===" << RESET << std::endl;
	{
		Intern someRandomIntern;
		AForm *form1 = someRandomIntern.makeForm("shrubbery creation", "Home");
		AForm *form2 = someRandomIntern.makeForm("robotomy request", "Bender");
		AForm *form3 = someRandomIntern.makeForm("presidential pardon", "Zaphod");

		std::cout << std::endl;
		if (form1) std::cout << *form1 << std::endl;
		if (form2) std::cout << *form2 << std::endl;
		if (form3) std::cout << *form3 << std::endl;

		delete form1;
		delete form2;
		delete form3;
	}

	std::cout << CYAN << "\n=== [Test 2] Intern gets invalid request ===" << RESET << std::endl;
	{
		Intern intern;
		AForm *bad = intern.makeForm("marriage approval", "Alice");
		if (!bad)
			std::cout << RED << "Form creation failed as expected." << RESET << std::endl;
		delete bad;
	}

	std::cout << CYAN << "\n=== [Test 3] Bureaucrat executes forms created by Intern ===" << RESET << std::endl;
	{
		try
		{
			Intern intern;
			Bureaucrat boss("Boss", 1);

			AForm *form = intern.makeForm("robotomy request", "TargetX");
			if (!form)
				throw std::runtime_error("Intern failed to create form");

			std::cout << boss << std::endl;
			std::cout << *form << std::endl;

			boss.signForm(*form);
			boss.executeForm(*form);

			delete form;
		}
		catch (const std::exception &e)
		{
			std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}

	std::cout << CYAN << "\n=== [Test 4] Form execution fails due to low grade ===" << RESET << std::endl;
	{
		try
		{
			Intern intern;
			Bureaucrat jim("Jim", 140);

			AForm *form = intern.makeForm("shrubbery creation", "Backyard");
			if (!form)
				throw std::runtime_error("Intern failed to create form");

			std::cout << jim << std::endl;
			std::cout << *form << std::endl;

			jim.signForm(*form);
			jim.executeForm(*form); // should fail because execGrade too high

			delete form;
		}
		catch (const std::exception &e)
		{
			std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}

	std::cout << CYAN << "\n=== End of Intern tests ===" << RESET << std::endl;
	return 0;
}
