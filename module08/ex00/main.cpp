#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stdexcept>
#include "easyfind.hpp"

void printSeparator(const std::string &title)
{
	std::cout << YELLOW << "================= " << title << " =================" << RESET << std::endl;
}


int main(void)
{
	std::cout << CYAN << "\n########## TESTING easyfind ##########\n" << RESET;

	printSeparator("VECTOR");
	std::vector<int> v;
	for (int i = 1; i <= 5; ++i)
		v.push_back(i * 10);

	try {
		std::vector<int>::iterator it = easyfind(v, 30);
		std::cout << GREEN << "Found in vector: " << *it << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	try {
		easyfind(v, 99);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	// ======= TEST 2: std::list<int> =======
	printSeparator("LIST");
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(10);
	lst.push_back(15);

	try {
		std::list<int>::iterator it = easyfind(lst, 10);
		std::cout << GREEN << "Found in list: " << *it << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	// ======= TEST 3: const std::deque<int> =======
	printSeparator("CONST DEQUE");
	const std::deque<int> dq(3, 7);

	try {
		std::deque<int>::const_iterator it = easyfind(dq, 7);
		std::cout << GREEN << "Found in const deque: " << *it << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	try {
		easyfind(dq, 0);
	}
	catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	std::cout << BLUE << "\n########## ALL TESTS DONE ##########\n" << RESET;
	return 0;
}