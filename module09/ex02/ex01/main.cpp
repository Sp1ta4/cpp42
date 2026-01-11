#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
		std::cout << "Enter only 1 argument: was given - " << argc - 1 << std::endl;
	else
	{
		RPN a;

		a.start(argv[1]);
	}
}