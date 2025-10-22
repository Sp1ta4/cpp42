#include "Character.hpp"

Character::Character() : _name("NO_NAME") {
	std::cout << "Default constructor of Character called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string const & name) : _name(name) {
	std::cout << "Constructor of Character with parameters called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& other) {
	std::cout << "Copy constructor of Character was called" << std::endl;
	_name = other._name;
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character&	Character::operator=(const Character& other) {
	std::cout << "Copy assignment of Character operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < 4; i++) {
			if (_inventory[i])
				delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

std::string const & Character::getName() const {
	return (this->_name);
}

void	Character::equip(AMateria* m) {
	std::cout << "Character equip was called" << std::endl;
	if (!m)
		return ;
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			return ;
		}
	}
	std::cout << YELLOW << "Inventory is full!" << RESET <<  std::endl;
}

void	Character::unequip(int idx) {
	std::cout << "Character unequip was called" << std::endl;
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx] = NULL;
}
void	Character::use(int idx, ICharacter& target) {
	std::cout << "Character use was called" << std::endl;
	if (idx >= 0 &&  idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
}

Character::~Character() {
	std::cout << "Destructor of Character called" << std::endl;
	for (int i = 0; i < 4; i++){
		if (_inventory[i])
			delete _inventory[i];
	}
}