#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon)
	: _weapon(weapon)
{
	if (name.empty())
		this->_name = "NO_NAME";
	else
		this->_name = name;
}

HumanA::~HumanA(void)
{}

void HumanA::attack(void){
	std::cout << this -> _name
			  << " attacks with their "
			  << this -> _weapon.getType()
			  << std::endl;
}