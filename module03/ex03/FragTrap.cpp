#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
 
	std::cout << GRAY
              << "FragTrap Default constuctor called!"
              << RESET << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;

    std::cout << GRAY
              << "FragTrap Argument constuctor called!"
              << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << GRAY
              << "FragTrap Copy constuctor called!"
              << RESET << std::endl;
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << GRAY
			 << "FragTrap Copy assignment operator called!"
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

FragTrap::~FragTrap()
{
    std::cout << GRAY
              << "FragTrap Destructor called!"
              << RESET << std::endl;
}

void	FragTrap::highFivesGuys( void ) {
	std::cout << this->_name
			  << " send high five request to members!"
			  << std::endl;
}
