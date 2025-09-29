#include <string>
#include <iostream>

using std::string;

int main()
{
	string str = "HI THIS IS BRAIN";
	string *stringPTR = &str;
	string &stringREF = str;

	std::cout << "\033[33mThe memory address of the string variable: \033[0m" << &str << std::endl;
	std::cout << "\033[33mThe memory address held by stringPTR: \033[0m" << stringPTR << std::endl;
	std::cout << "\033[33mThe memory address held by stringREF: \033[0m" << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "\033[33mThe value of the string variable: \033[0m" << str << std::endl;
	std::cout << "\033[33mThe value pointed to by stringPTR: \033[0m" << *stringPTR << std::endl;
	std::cout << "\033[33mThe value pointed to by stringREF: \033[0m" << stringREF << std::endl;

	return 0;
}
