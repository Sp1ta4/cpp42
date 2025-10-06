#include "ScavTrap.hpp"

int	main(void) {

	ScavTrap a("Josh");
	ScavTrap b;
	ScavTrap c;

	c = a;
	b = a;

	c.attack("Benedikt");
	c.takeDamage(75);
	c.beRepaired(155);
	c.guardGate();
	b.attack("Bob");
	b.takeDamage(150);
	b.beRepaired(15);
	b.guardGate();
	return (0);
}
