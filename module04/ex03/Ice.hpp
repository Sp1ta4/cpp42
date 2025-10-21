#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class Ice : public AMateria
{
	protected:
		std::string const &_type;
	public:
		Ice();
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};


#endif