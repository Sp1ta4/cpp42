#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << BLUE << "===== RANDOM GENERATION TEST =====" << RESET << std::endl;
	for (int i = 0; i < 5; i++)
	{
		Base *ptr = Base::generate();
		std::cout << CYAN << "Generated class " << i + 1 << ": " << RESET;
		Base::identify(ptr);
		std::cout << std::endl;
		delete ptr;
	}
	std::cout << std::endl;

	std::cout << BLUE << "===== STATIC TYPE TESTS =====" << RESET << std::endl;

	Base base;
	A a;
	B b;
	C c;

	std::cout << YELLOW << "identify(Base&)   -> " << RESET;
	Base::identify(base);
	std::cout << std::endl;

	std::cout << YELLOW << "identify(A&)      -> " << RESET;
	Base::identify(a);
	std::cout << std::endl;

	std::cout << YELLOW << "identify(B&)      -> " << RESET;
	Base::identify(b);
	std::cout << std::endl;

	std::cout << YELLOW << "identify(C&)      -> " << RESET;
	Base::identify(c);
	std::cout << std::endl;

	std::cout << std::endl
			  << GREEN << "All tests finished successfully!" << RESET << std::endl;

	return (0);
}