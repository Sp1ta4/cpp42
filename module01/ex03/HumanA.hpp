#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA {
	private:
		Weapon		&_weapon;
		std::string _name;
	public:
		HumanA(const std::string &name, Weapon &weapon);
		~HumanA(void);
		void attack(void);
};

#endif