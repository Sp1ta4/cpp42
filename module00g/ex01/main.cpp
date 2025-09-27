#include "main.hpp"

bool isEOF()
{
	return (std::cin.eof());
}

int main(void)
{
	PhoneBook phoneBook;
	std::string inputCode;

	while (true)
	{
		if (isEOF())
			break;

		std::cout << "\033[35mThe program only accepts ADD, SEARCH and EXIT.\033[0m" << std::endl;
		std::getline(std::cin, inputCode);

		if (inputCode == ADD_CODE)
			phoneBook.addContact();
		else if (inputCode == SEARCH_CODE)
			phoneBook.searchContact();
		else if (inputCode == EXIT_CODE)
			break;
	};
	return (0);
}
