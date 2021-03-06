#include <iostream>
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap *a = new ClapTrap("a");
	ClapTrap b("b");
	ClapTrap c;

	c = b;
	a->attack("bbb");
	a->takeDamage(13);
	a->beRepaired(20);

	b.takeDamage(10);
	b.beRepaired(10);

	std::cout << "Name: " << c.getName() << std::endl;
	std::cout << "Hit Points: " << c.getHitPoints() << std::endl;
	std::cout << "Energy: " << c.getEnergy() << std::endl;
	std::cout << "Attack Demage: " << c.getAttackDemage() << std::endl;

	std::cout << *a << std::endl << b << std::endl;

	delete a;
}
