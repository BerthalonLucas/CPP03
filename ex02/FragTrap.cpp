#include "FragTrap.hpp"
#include "Colors.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << BOLD_GREEN << "Default constructor called. A new FragTrap is born!" << RESET << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << BOLD_GREEN << "Constructor for " << BOLD_CYAN << name << RESET << BOLD_GREEN << " called. A new FragTrap is born! Ready to rumble!" << RESET << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap& copy) : ClapTrap(copy) {
	std::cout << BOLD_YELLOW << "Copy constructor called. Cloning Scav the " << BOLD_CYAN << copy._name << RESET << BOLD_YELLOW << "!" << RESET << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << BOLD_RED << "Destructor called. FragTrap signing off!" << RESET << std::endl;
}

void FragTrap::attack(const std::string& target) {
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

void FragTrap::takeDamage(unsigned int amount) {
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

void FragTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints <= 0){
		if (!this->_name.empty())
			std::cout << BOLD_RED << this->_name << " is out of commission and can't be repaired!" << RESET << std::endl;
	}
	else {
		if (this->_energyPoints <= 0){
			if (!this->_name.empty())
				std::cout << BOLD_YELLOW << "Not enough energy points for " << this->_name << " to be repaired. Time for a recharge!" << RESET << std::endl;
			return ;
		}
		this->_hitPoints += amount;
		if (this->_hitPoints > 100)
			this->_hitPoints = 100;
		if (!this->_name.empty())
			std::cout << BOLD_BLUE << this->_name << " has been repaired for " << amount << " hit points!" << RESET << std::endl;
	}
}

void FragTrap::highFivesGuys(void) {
	if (this->_hitPoints <= 0){
		if (!this->_name.empty())
			std::cout << BOLD_RED << this->_name << " is out of commission and can't high five!" << RESET << std::endl;
	}
	else if (this->_energyPoints <= 0){
		if (!this->_name.empty())
			std::cout << BOLD_YELLOW << "Not enough energy points for " << this->_name << " to high five. Time for a recharge!" << RESET << std::endl;
	}
	else {
		std::cout << BOLD_CYAN << this->_name << " high fives the guys! ✋" << RESET << std::endl;
		this->_energyPoints -= 1;
	}
}

unsigned int FragTrap::getEnergyPoints(void) const {
	return this->_energyPoints;
}

FragTrap& FragTrap::operator=(FragTrap& copy) {
	std::cout << BOLD_YELLOW << "Assignation operator called. Copying " << BOLD_CYAN << copy._name << RESET << BOLD_YELLOW << "!" << RESET << std::endl;
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	return *this;
}