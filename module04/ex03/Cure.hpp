#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class Cure : public AMateria
{
	protected:
		std::string const &_type;
	public:
		Cure();
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};


#endif
