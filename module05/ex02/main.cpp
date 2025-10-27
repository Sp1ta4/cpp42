#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << CYAN << "\n=== [Test 1] Valid Form Signing ===" << RESET << std::endl;
	{
		try
		{
			Bureaucrat bob("Bob", 50);
			Form form("TaxForm", 75, 100);

			std::cout << bob << std::endl;
			std::cout << form << std::endl;

			bob.signForm(form); // should succeed
			std::cout << GREEN << "Form successfully signed!" << RESET << std::endl;
			std::cout << form << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}

	std::cout << CYAN << "\n=== [Test 2] Grade too low to sign ===" << RESET << std::endl;
	{
		try
		{
			Bureaucrat jim("Jim", 100);
			Form secret("SecretForm", 25, 50);

			std::cout << jim << std::endl;
			std::cout << secret << std::endl;

			jim.signForm(secret); // should fail (grade too low)
			std::cout << secret << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}

	std::cout << CYAN << "\n=== [Test 3] Invalid form grades ===" << RESET << std::endl;
	{
		try
		{
			Form invalidHigh("InvalidHigh", 0, 75); // grade < 1
		}
		catch (const std::exception &e)
		{
			std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
		}

		try
		{
			Form invalidLow("InvalidLow", 200, 150); // grade > 150
		}
		catch (const std::exception &e)
		{
			std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}

	std::cout << CYAN << "\n=== [Test 4] Copy and assignment ===" << RESET << std::endl;
	{
		try
		{
			Form formA("FormA", 80, 100);
			Bureaucrat alice("Alice", 75);

			alice.signForm(formA);
			std::cout << formA << std::endl;

			Form formB(formA); // copy constructor
			std::cout << "Copied: " << formB << std::endl;

			Form formC("FormC", 120, 130);
			formC = formA; // assignment
			std::cout << "Assigned: " << formC << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}

	std::cout << CYAN << "\n=== [Test 5] Bureaucrat promotion/demotion affecting signing ===" << RESET << std::endl;
	{
		try
		{
			Bureaucrat mike("Mike", 100);
			Form form("WorkPermit", 90, 90);

			std::cout << mike << std::endl;
			mike.signForm(form); // should fail first

			std::cout << YELLOW << "Trying to promote Mike..." << RESET << std::endl;
			for (int i = 0; i < 15; ++i)
				mike.incrementGrade();

			std::cout << mike << std::endl;
			mike.signForm(form); // should succeed now
			std::cout << form << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
		}
	}

	std::cout << CYAN << "\n=== End of tests ===" << RESET << std::endl;
	return 0;
}
