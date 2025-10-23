#include "Bureaucrat.hpp"

int main()
{
	std::cout << CYAN << "=== Bureaucrat Class Tests ===" << RESET << std::endl;

	try
	{
		std::cout << YELLOW << "\n[Test 1] Creating a valid Bureaucrat..." << RESET << std::endl;
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl;

		std::cout << GREEN << "Incrementing grade..." << RESET << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl;

		std::cout << GREEN << "Decrementing grade..." << RESET << std::endl;
		bob.decrementGrade();
		std::cout << bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << YELLOW << "\n[Test 2] Creating Bureaucrat with grade too high (0)..." << RESET << std::endl;
		Bureaucrat alice("Alice", 0);
		std::cout << alice << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << YELLOW << "\n[Test 3] Creating Bureaucrat with grade too low (151)..." << RESET << std::endl;
		Bureaucrat john("John", 151);
		std::cout << john << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << YELLOW << "\n[Test 4] Incrementing beyond limit..." << RESET << std::endl;
		Bureaucrat top("Top", 1);
		std::cout << top << std::endl;
		top.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << YELLOW << "\n[Test 5] Decrementing beyond limit..." << RESET << std::endl;
		Bureaucrat bottom("Bottom", 150);
		std::cout << bottom << std::endl;
		bottom.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== End of Tests ===" << RESET << std::endl;
	return 0;
}
