#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char const *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (size_t j = 0; argv[i][j] != '\0'; ++j)
			{
				std::cout << char(toupper(argv[i][j]));
			}
		}
	}
	std::cout << std::endl;
	return 0;
}
