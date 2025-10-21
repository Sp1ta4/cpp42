#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << GREEN << "########TESTING########" << RESET << std::endl;
	std::cout << std::endl << GREEN << "########CREATING########" << RESET << std::endl;

	const Animal		*defaultAnimal = new Animal("Monkey");
	const Animal		*dog = new Dog();
	const Animal		*cat = new Cat();
	const WrongAnimal	*wrongCat = new WrongCat();
	
	std::cout << YELLOW << "########CALLING GET_TYPE########" << RESET << std::endl;

	std::cout << defaultAnimal->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	
	std::cout << YELLOW << "########CALLING MAKE_SOUND########" << RESET << std::endl;

	defaultAnimal->makeSound();
	cat->makeSound();
	dog->makeSound();
	wrongCat->makeSound();

	std::cout << RED << "########CALLING DESTRUCTORS########" << RESET << std::endl;

	delete defaultAnimal;
	delete dog;
	delete cat;
	delete wrongCat;
}