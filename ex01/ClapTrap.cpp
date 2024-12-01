#include "ClapTrap.hpp"
#include "Colors.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)  {
	std::cout << BOLD_GREEN << "Default constructor called. A new ClapTrap is born!" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << BOLD_GREEN << "Constructor for " << BOLD_CYAN << name << RESET << BOLD_GREEN << " called. Ready to rumble!" << RESET << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << BOLD_RED << "Destructor called. ClapTrap signing off!" << RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& copy) {
	std::cout << BOLD_YELLOW << "Copy constructor called. Cloning " << BOLD_CYAN << copy._name << RESET << BOLD_YELLOW << "!" << RESET << std::endl;
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
}

void ClapTrap::attack(const std::string& target) {
	if (this->_hitPoints <= 0){
		if (!this->_name.empty())
			std::cout << BOLD_RED << this->_name << " is out of commission and can't attack!" << RESET << std::endl;
	}
	else if (this->_energyPoints <= 0){
		if (!this->_name.empty())
			std::cout << BOLD_YELLOW << "Not enough energy points for " << this->_name << " to attack. Time for a recharge!" << RESET << std::endl;
	}
	else {
		std::cout << BOLD_MAGENTA << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << RESET << std::endl;
		this->_energyPoints -= 1;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints <= 0){
		if (!this->_name.empty())
			std::cout << BOLD_RED << this->_name << " is already out. No need to kick a robot when it's down!" << RESET << std::endl;
	}
	else {
		if (amount > this->_hitPoints)
			amount = this->_hitPoints;
		this->_hitPoints -= amount;
		if (this->_hitPoints <= 0){
			if (!this->_name.empty())
				std::cout << BOLD_RED << this->_name << " has been destroyed! So much for warranty..." << RESET << std::endl;
		}
		else {
			if (!this->_name.empty())
				std::cout << BOLD_YELLOW << this->_name << " takes " << amount << " damage. Ouch!" << RESET << std::endl;
		}
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints <= 0){
		if (!this->_name.empty())
			std::cout << BOLD_RED << this->_name << " is beyond repair. Time to build a new one!" << RESET << std::endl;
	}
	else {
		this->_hitPoints += amount;
		if (this->_hitPoints > 10)
			this->_hitPoints = 10;
		if (!this->_name.empty())
			std::cout << BOLD_GREEN << this->_name << " repairs itself and now has " << this->_hitPoints << " hit points. Back in action!" << RESET << std::endl;
	}
}


