#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
	std::cout << "\n--- Test 1: Création et destruction ---" << std::endl;
	{
		ScavTrap scav("Scavy");
	}

	std::cout << "\n----------------------------------------\n" << std::endl;

	std::cout << "\n--- Test 2: Fonctions héritées ---" << std::endl;
	ScavTrap scav2("Guardian");
	scav2.attack("Enemy");
	scav2.takeDamage(30);
	scav2.beRepaired(20);
	scav2.takeDamage(200);

	std::cout << "\n----------------------------------------\n" << std::endl;

	std::cout << "\n--- Test 3: Fonction spécifique guardGate ---" << std::endl;
	{
		ScavTrap scavG("Guardian");
		scavG.guardGate();
	}

	std::cout << "\n----------------------------------------\n" << std::endl;

	std::cout << "\n--- Test 4: Constructeur de copie ---" << std::endl;
	ScavTrap scav3(scav2);
	scav3.attack("Another Enemy");

	std::cout << "\n----------------------------------------\n" << std::endl;

	std::cout << "\n--- Test 5: Test d'héritage ---" << std::endl;
	ClapTrap clap("Clappy");
	clap.attack("A simple target");
	clap.takeDamage(5);
	clap.beRepaired(10);

	std::cout << "\n----------------------------------------\n" << std::endl;

	std::cout << "\n--- Test 6: Limites d'énergie ---" << std::endl;
	{
		ScavTrap scav4("Guardian");
		for (int i = 0; i < 52; ++i) {
			scav4.attack("Target");
		}
		scav4.beRepaired(10);
	}

	std::cout << "\n--- Fin des tests ---" << std::endl;
	return 0;
}
