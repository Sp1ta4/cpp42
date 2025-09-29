#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	Weapon *_weapon;
	std::string _name;

public:
	HumanB(const std::string &name);
	~HumanB(void);
	void setWeapon(Weapon &weapon);
	void attack(void) const;
};

#endif