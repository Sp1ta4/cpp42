#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() 
    : ClapTrap("NO_NAME_clap_name"), ScavTrap(), FragTrap(), _name("NO_NAME") {
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
	std::cout << GRAY
              << "DiamondTrap Default constuctor called!"
              << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) 
    : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name) {
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << GRAY
              << "DiamondTrap Argument constuctor called!"
              << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) 
    : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
		    std::cout << GRAY
              << "DiamondTrap Copy constuctor called!"
              << RESET << std::endl;
		*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << GRAY
         << "DiamondTrap Copy assignment operator called!"
         << RESET << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
		ClapTrap::_name = other.ClapTrap::_name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << GRAY
              << "DiamondTrap Destructor called!"
              << RESET << std::endl;
}

void DiamondTrap::whoAmI(void) {
    std::cout << "I am DiamondTrap named "
			  << this->_name
              << " and my ClapTrap name is "
			  << ClapTrap::_name << std::endl;
}
