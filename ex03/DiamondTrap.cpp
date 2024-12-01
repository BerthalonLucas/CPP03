#include "DiamondTrap.hpp"
#include "Colors.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << BOLD_GREEN << "Diamond default constructor called. A new DiamondTrap is born!" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap& copy) {
	std::cout << BOLD_YELLOW << "DiamondTrap copy constructor called. Cloning " << BOLD_CYAN << copy._name << RESET << BOLD_YELLOW << "!" << RESET << std::endl;
	this->_name = copy._name;
}

DiamondTrap::DiamondTrap(std::string name) {
	std::cout << BOLD_GREEN << "Diamond constructor for " << BOLD_CYAN << name << RESET << BOLD_GREEN << " called. A new DiamondTrap is born! Ready to rumble!" << RESET << std::endl;
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
	std::cout << BOLD_WHITE << "DiamondTrap " << this->_name << " has " << this->_hitPoints << " hit points, " << this->_energyPoints << " energy points, and " << this->_attackDamage << " attack damage." << RESET << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << BOLD_RED << "DiamondTrap destructor called. " << this->_name << " is no more." << RESET << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << BOLD_CYAN << "I am " << this->_name << " and I am a DiamondTrap!" << RESET << std::endl;
	std::cout << BOLD_CYAN << "My ClapTrap name is " << this->ClapTrap::getName() << RESET << std::endl;
}

void DiamondTrap::attack(std::string const & target) {
	FragTrap::_name = this->_name;
	FragTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount) {
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
				std::cout << BOLD_YELLOW << this->_name << " has taken " << amount << " points of damage and has " << this->_hitPoints << " hit points left." << RESET << std::endl;
		}
	}
}

void DiamondTrap::beRepaired(unsigned int amount) {
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
			std::cout << BOLD_YELLOW << this->_name << " has been repaired for " << amount << " points and now has " << this->_hitPoints << " hit points." << RESET << std::endl;
	}
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap& copy) {
	std::cout << BOLD_YELLOW << "DiamondTrap assignment operator called. Copying " << BOLD_CYAN << copy._name << RESET << BOLD_YELLOW << "!" << RESET << std::endl;
	this->_name = copy._name;
	return *this;
}