#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>
# include <string>

# define RESET "\033[0m"
# define RED "\033[031m"
# define GREEN "\033[032m"
# define YELLOW "\033[033m"
# define PURPLE "\033[035m"
# define GRAY "\033[037m"
# define ORANGE "\033[48;2;255;165;0m"


class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal(void);
		WrongAnimal(const std::string& type);
		WrongAnimal(const WrongAnimal& other);
		virtual ~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal& other);
		
		std::string	getType() const;
		void makeSound(void) const;
};

#endif