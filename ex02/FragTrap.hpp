#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(FragTrap& copy);
		FragTrap(std::string name);
		~FragTrap();
		FragTrap& operator=(FragTrap& copy);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void highFivesGuys(void);
		unsigned int getEnergyPoints(void) const;
};

#endif
