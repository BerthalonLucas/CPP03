#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
	std::string _name;
	public:
	DiamondTrap();
	DiamondTrap(DiamondTrap& copy);
	DiamondTrap(std::string name);
	~DiamondTrap();
	DiamondTrap& operator=(DiamondTrap& copy);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void attack(std::string const & target);
	void whoAmI();
};

#endif
