#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal		*defaultAnimal = new Animal("Monkey");
	const Animal		*dog = new Dog();
	const Animal		*cat = new Cat();
	const WrongAnimal	*wrongCat = new WrongCat();

	std::cout << defaultAnimal->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	
	cat->makeSound();
	dog->makeSound();
	wrongCat->makeSound();
	defaultAnimal->makeSound();

	delete defaultAnimal;
	delete dog;
	delete cat;
	delete wrongCat;
}