#include "HumanB.hpp"

HumanB::HumanB(const std::string &name)
	: _weapon(NULL)
{
	if (name.empty())
		this->_name = "NO_NAME";
	else
		this->_name = name;
}

HumanB::~HumanB(void)
{
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack() const
{
	if (this->_weapon && this->_weapon->getType() != "")
		std::cout << this->_name
				  << "  attacks with their "
				  << this->_weapon->getType()
				  << std::endl;
	else
		std::cout << this->_name
				  << "  attacks with their "
				  << "hand" << std::endl;
}