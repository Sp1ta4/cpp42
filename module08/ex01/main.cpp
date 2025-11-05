#include "Span.hpp"

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	return 0;
// }

void printSeparator(const std::string &title)
{
	std::cout << YELLOW << "======= " << title << " =======" << RESET << std::endl;
}

int main()
{
	srand(time(NULL));

	try {
		printSeparator("SIMPLE TEST");

		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << GREEN << "Shortest span: " << sp.shortestSpan() << RESET << std::endl;
		std::cout << GREEN << "Longest span: " << sp.longestSpan() << RESET << std::endl;

		printSeparator("TEST addNumbers with vector");

		std::vector<int> v;
		for (int i = 0; i < 10; ++i)
			v.push_back(i * 3);

		Span sp2(10);
		sp2.addNumbers(v.begin(), v.end());
		std::cout << GREEN << "Shortest span: " << sp2.shortestSpan() << RESET << std::endl;
		std::cout << GREEN << "Longest span: " << sp2.longestSpan() << RESET << std::endl;

		printSeparator("TEST addNumbers with list");

		std::list<int> lst;
		for (int i = 0; i < 15; ++i)
			lst.push_back(rand() % 1000);

		Span sp3(15);
		sp3.addNumbers(lst.begin(), lst.end());
		std::cout << GREEN << "Shortest span: " << sp3.shortestSpan() << RESET << std::endl;
		std::cout << GREEN << "Longest span: " << sp3.longestSpan() << RESET << std::endl;

		printSeparator("BIG TEST (10,000 numbers)");

		Span big(10000);
		for (int i = 0; i < 10000; ++i)
			big.addNumber(rand());

		std::cout << CYAN << "Shortest span: " << big.shortestSpan() << RESET << std::endl;
		std::cout << CYAN << "Longest span: " << big.longestSpan() << RESET << std::endl;

	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "\nAll tests done!" << RESET << std::endl;

	return 0;
}
