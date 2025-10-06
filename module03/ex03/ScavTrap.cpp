#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
 
	std::cout << GRAY
              << "ScavTrap Default constuctor called!"
              << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;

    std::cout << GRAY
              << "ScavTrap Argument constuctor called!"
              << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << GRAY
              << "ScavTrap Copy constuctor called!"
              << RESET << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << GRAY
			 << "ScavTrap Copy assignment operator called!"
			 << RESET << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{

    std::cout << GRAY
              << "ScavTrap Destructor called!"
              << RESET << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_energyPoints <= 0)
    {
        std::cout << RED
                  << "You cant attack with no energy points!"
                  << RESET
                  << std::endl;
        return;
    }
    if (target.empty()) {
		std::cout << GREEN 
                  << "ScavTrap " << this->_name << " attack " << "NO_NAME";
        std::cout << ", causing " << this->_attackDamage << " points of damage!"
                  << RESET << std::endl; 
	}
	else {
		
		std::cout << GREEN 
                  << "ScavTrap " << this->_name << " attack " << target;
        std::cout << ", causing " << this->_attackDamage << " points of damage!"
                  << RESET << std::endl; 
	}
	--(this->_energyPoints);
}

void ScavTrap::guardGate(void) {
	std::cout << YELLOW
			  << "ScavTrap "
			  << this->_name
			  << " have enterred in Gate keeper mode!"
			  << RESET << std::endl;
}