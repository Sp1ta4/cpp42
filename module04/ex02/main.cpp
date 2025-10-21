#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << BLUE << "=== Animal Polymorphism Test ===" << RESET << std::endl;
	// Animal a; // ABSTRACT CLASS, CANNOT INSTANTIATE
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "\n" << GREEN << "[TYPES]" << RESET << std::endl;
	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;

	std::cout << "\n" << GREEN << "[SOUNDS]" << RESET << std::endl;
	std::cout << "Dog makes sound: ";
	dog->makeSound();

	std::cout << "Cat makes sound: ";
	cat->makeSound();

	std::cout << "\n" << GREEN << "[DESTRUCTION]" << RESET << std::endl;
	delete dog;
	delete cat;

	std::cout << "\n" << BLUE << "===  Copy & Assignment Test ===" << RESET << std::endl;

	Dog originalDog;
	{
		std::cout << YELLOW << "\nCreating a copyDog from originalDog" << RESET << std::endl;
		Dog copyDog(originalDog);
		std::cout << YELLOW << "Assigning anotherDog = copyDog" << RESET << std::endl;
		Dog anotherDog;
		anotherDog = copyDog;
	}

	std::cout << "\n" << BLUE << "===  Test Completed ===" << RESET << std::endl;
	return 0;
}