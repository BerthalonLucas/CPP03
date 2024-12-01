#include "ClapTrap.hpp"

int main(void) {
	ClapTrap claptrap("Claptrap");
	ClapTrap claptrap2(claptrap);
	ClapTrap claptrap3;
	ClapTrap claptrap4("Claptrap4");

	claptrap.attack("enemy");
	claptrap.takeDamage(5);
	claptrap.beRepaired(4);
	claptrap.attack("enemy");
	claptrap.attack("enemy");
	claptrap.attack("enemy");
	claptrap.attack("enemy");
	claptrap.attack("enemy");
	claptrap.attack("enemy");
	claptrap.attack("enemy");
	claptrap.attack("enemy");
	claptrap.attack("enemy");
	claptrap.attack("enemy");
	claptrap.takeDamage(5);
	claptrap.takeDamage(5);
	claptrap.beRepaired(5);
	claptrap.attack("enemy");
}