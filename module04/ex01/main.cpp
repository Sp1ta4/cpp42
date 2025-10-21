#include "Dog.hpp"
#include "Cat.hpp"

int	main(void) {

	unsigned int size = 4;
	Animal* animals[size];

	unsigned int i = 0;

	std::cout << std::endl;
	std::cout << PURPLE << "#############################################" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << GREEN << "Creating array of Dog's" << RESET << std::endl;

	while(i < size / 2) {
		std::cout << BLUE << "---------------------------------------------" << RESET << std::endl;
		animals[i] = new Dog();
		i++;
	}

	std::cout << BLUE << "---------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << GREEN << "Creating array of Cat's" << RESET << std::endl;

	while(i < size) {
		std::cout << BLUE << "---------------------------------------------" << RESET << std::endl;
		animals[i] = new Cat();
		i++;
	}

	std::cout << BLUE << "---------------------------------------------" << RESET << std::endl;
	std::cout << std::endl;

	std::cout << PURPLE << "########### Deep copy test ############" << RESET << std::endl;
	std::cout << std::endl;

	Dog* basicDog = new Dog();
	basicDog->getBrain()->setIdea(0, "I want food");

	Dog copiedDog = *basicDog;

	std::cout << YELLOW << "Original Dog idea: " << RESET
	          << basicDog->getBrain()->getIdea(0) << std::endl;
	std::cout << YELLOW << "Copied Dog idea:   " << RESET
	          << copiedDog.getBrain()->getIdea(0) << std::endl;

	basicDog->getBrain()->setIdea(0, "I want to play!");

	std::cout << std::endl;
	std::cout << YELLOW << "After change:" << RESET << std::endl;
	std::cout << "Original Dog idea: " << basicDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied Dog idea:   " << copiedDog.getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	std::cout << "\033[31mDeleting the array" << RESET << std::endl;

	i = 0;
	while (i < size) {
		std::cout << BLUE << "------------------------------------" << RESET << std::endl;
		delete animals[i];
		i++;
	}

	std::cout << BLUE << "------------------------------------" << RESET << std::endl;
	
	delete basicDog;

	std::cout << std::endl;
	std::cout << PURPLE << "#############################################" << RESET << std::endl;
	std::cout << std::endl;

	return (0);
}