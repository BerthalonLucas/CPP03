#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "Colors.hpp"

int main(void) {
	DiamondTrap diamondTrap("bloublou");
	diamondTrap.whoAmI();
	diamondTrap.attack("target");
	diamondTrap.takeDamage(10);
	diamondTrap.beRepaired(10);
	return 0;
}