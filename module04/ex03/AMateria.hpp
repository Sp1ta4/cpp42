#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"

class ICharacter;

class	AMateria {
	protected:
		std::string	_type;
	
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other); 
		virtual ~AMateria();

		std::string const &	getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};


#endif