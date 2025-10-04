#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
    : _name("NO_NAME")
    , _hitPoints(10)
    , _energyPoints(10)
    , _attackDamage(0)
{
    std::cout << GRAY
              << "Default constuctor called!"
              << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name.empty() ? "NO_NAME" : name)
    , _hitPoints(10)
    , _energyPoints(10)
    , _attackDamage(0)
{
    std::cout << GRAY
              << "Argument constuctor called!"
              << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << GRAY
              << "Copy constuctor called!"
              << RESET << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
     std::cout << GRAY
              << "Copy operator constuctor called!"
              << RESET << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{

    std::cout << GRAY
              << "Deconstuctor called!"
              << RESET << std::endl;
}


void ClapTrap::attack(const std::string& target)
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
                  << "ClapTrap " << this->_name << " attack " << "NO_NAME";
        std::cout << ", causing " << this->_attackDamage << " points of damage!"
                  << RESET << std::endl; 
	}
	else {
		
		std::cout << GREEN 
                  << "ClapTrap " << this->_name << " attack " << target;
        std::cout << ", causing " << this->_attackDamage << " points of damage!"
                  << RESET << std::endl; 
	}
	--(this->_energyPoints);
}

void ClapTrap::takeDamage(unsigned  int amount) {
	if (this->_energyPoints == 0)
    {
		std::cout << RED
                  << "You cant attack with no energy points!"
                  << RESET
                  << std::endl;
        return ;
    }
	if (this->_hitPoints == 0)
		std::cout << PURPLE
                   << "ClapTrap " << this->_name
                   << " already died and cant got damage."
                   << RESET << std::endl;
	else
	{
		std::cout << ORANGE
                  << "ClapTrap " << this->_name << " has got " << amount << " damages!"
                  << RESET << std::endl;
		if (amount <= this->_hitPoints)
			this->_hitPoints -= amount;
		else
			this->_hitPoints = 0;
	}
}

void	ClapTrap::beRepaired( unsigned  int amount ) {
	if (this->_energyPoints <= 0)
    {
        std::cout << RED
                  << "You cant attack with no energy points!"
                  << RESET
                  << std::endl;
        return;
    }
    if (this->_hitPoints == 0)
		std::cout << PURPLE
                   << "ClapTrap " << this->_name
                   << " already died and cant be repaired."
                   << RESET << std::endl;
	else
	{
		std::cout << GREEN
                  << "ClapTrap " << this->_name << " has been repaired by " << amount << " points!"
                  << RESET << std::endl;
		this->_hitPoints += amount;
	}
}
