#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
class Dog : public Animal
{
	private:
		Brain* _brain;
	public:
		Dog(void);
		Dog(const Dog& other);
		~Dog();
		Dog& operator=(const Dog& other);
		
		Brain* getBrain() const;
		void makeSound(void) const;
};




#endif