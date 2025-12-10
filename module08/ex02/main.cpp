#include "MutantStack.hpp"
//########################## DEFAULT TESTS #######################//

int	main(void)
{
	std::cout << CYAN << "======= TESTING MutantStack =======" << RESET << std::endl;

	MutantStack<int> mstack;

	std::cout << BLUE << "\n--- Basic stack operations ---" << RESET << std::endl;

	mstack.push(5);
	mstack.push(17);

	std::cout << GREEN << "Top element: " << RESET << mstack.top() << std::endl;

	mstack.pop();
	std::cout << YELLOW << "After pop, size: " << RESET << mstack.size() << std::endl;

	std::cout << RED << "***********************************************" << RESET << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << BLUE << "\n--- Iterating through MutantStack ---" << RESET << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	int i = 0;
	while (it != ite)
	{
		std::cout << MAGENTA << "Element [" << i++ << "]: " << RESET << *it << std::endl;
		++it;
	}

	std::cout << RED << "***********************************************" << RESET << std::endl;

	std::cout << BLUE << "\n--- Copy constructing std::stack from MutantStack ---" << RESET << std::endl;

	std::stack<int> tmp(mstack);
	std::cout << GREEN << "Top element of std::stack copy: " << RESET << tmp.top() << std::endl;

	std::cout << RED << "***********************************************" << RESET << std::endl;

	std::cout << BLUE << "\n--- Copy constructing MutantStack ---" << RESET << std::endl;

	MutantStack<int> s(mstack);
	MutantStack<int>::const_reverse_iterator rit = s.rbegin();
	MutantStack<int>::const_reverse_iterator rite = s.rend();

	std::cout << YELLOW << "Iterating MutantStack in reverse order:" << RESET << std::endl;
	while (rit != rite)
	{
		std::cout << *rit << " ";
		++rit;
	}
	std::cout << std::endl;

	std::cout << RED << "***********************************************" << RESET << std::endl;
	std::cout << GREEN << "\nAll tests completed successfully" << RESET << std::endl;

	return (0);
}



//############### TEST WITH MUTANT_STACK ################//
// int main(void) {
// 	MutantStack<int> mstack;

// 	mstack.push(5);
// 	mstack.push(17);

// 	std::cout << RED "***********************************************" RESET << std::endl;
// 	std::cout << "Top element: " << mstack.top() << std::endl;

// 	mstack.pop();
// 	std::cout << "Size after pop: " << mstack.size() << std::endl;

// 	std::cout << RED "***********************************************" RESET << std::endl << std::endl;

// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	mstack.push(0);

// 	std::cout << YELLOW "Iterating MutantStack (forward):" RESET << std::endl;
// 	std::cout << YELLOW "***********************************************" RESET << std::endl;

// 	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
// 		std::cout << *it << std::endl;

// 	std::cout << YELLOW "***********************************************" RESET << std::endl << std::endl;

// 	std::cout << MAGENTA "Iterating MutantStack (reverse):" RESET << std::endl;
// 	std::cout << MAGENTA "***********************************************" RESET << std::endl;

// 	for (MutantStack<int>::const_reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
// 		std::cout << *rit << std::endl;

// 	std::cout << MAGENTA "***********************************************" RESET << std::endl;

// 	return 0;
// }



//############### TEST WITH LIST ###################//
/*
int main(void) {
	std::list<int> mlist;

	mlist.push_back(5);
	mlist.push_back(17);

	std::cout << RED "***********************************************" RESET << std::endl;
	std::cout << "Top element: " << mlist.back() << std::endl;

	mlist.pop_back();
	std::cout << "Size after pop: " << mlist.size() << std::endl;

	std::cout << RED "***********************************************" RESET << std::endl << std::endl;

	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);

	std::cout << YELLOW "Iterating std::list (forward):" RESET << std::endl;
	std::cout << YELLOW "***********************************************" RESET << std::endl;

	for (std::list<int>::iterator it = mlist.begin(); it != mlist.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << YELLOW "***********************************************" RESET << std::endl << std::endl;

	std::cout << MAGENTA "Iterating std::list (reverse):" RESET << std::endl;
	std::cout << MAGENTA "***********************************************" RESET << std::endl;

	for (std::list<int>::const_reverse_iterator rit = mlist.rbegin(); rit != mlist.rend(); ++rit)
		std::cout << *rit << std::endl;

	std::cout << MAGENTA "***********************************************" RESET << std::endl;

	return 0;
}*/
