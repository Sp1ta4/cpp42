#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

# define RESET "\033[0m"
# define RED "\033[031m"
# define GREEN "\033[032m"
# define YELLOW "\033[033m"
# define PURPLE "\033[035m"
# define GRAY "\033[037m"
# define ORANGE "\033[48;2;255;165;0m"


class Animal
{
	protected:
		std::string	type;
	public:
		Animal(void);
		Animal(const std::string& type);
		Animal(const Animal& other);
		virtual ~Animal();
		Animal& operator=(const Animal& other);
		
		std::string	getType() const;
		virtual void makeSound(void) const;
};

#endif