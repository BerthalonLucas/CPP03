#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <sstream>

#define SEPARATOR "\033[1;31m-----------------------------------------\033[0m"

int main() {
	std::cout << "\n" << SEPARATOR << "\n--- Test 1: Create and destroy ---" << std::endl;
	{
		FragTrap frag("Fraggy");
	}

	std::cout << "\n" << SEPARATOR << "\n--- Test 2: fontions from Heritage ---" << std::endl;
	FragTrap frag2("Destroyer");
	frag2.attack("Target Dummy");
	frag2.takeDamage(50);
	frag2.beRepaired(30);
	frag2.takeDamage(100);

	std::cout << "\n" << SEPARATOR << "\n--- Test 3: new fonction ---" << std::endl;
	frag2.highFivesGuys();

	std::cout << "\n" << SEPARATOR << "\n--- Test 4: copy constructor ---" << std::endl;
	FragTrap frag3(frag2);
	frag3.attack("Another Dummy");

	std::cout << "\n" << SEPARATOR << "\n--- Test 5: fonction of each classes ---" << std::endl;
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavy");
	FragTrap frag5("Fraggy");
	clap.attack("Generic Target");
	scav.guardGate();
	frag5.highFivesGuys();

	std::cout << "\n" << SEPARATOR << "\n--- Test 6: Limites d'énergie ---" << std::endl;
	{
		FragTrap frag6("Energy Tester");
		std::stringstream buffer;
		std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
		int y = 0;
		for (int i = 0; i < 120; ++i) {
			frag6.attack("Energy Test Target");
			y++;
		}
		std::cout.rdbuf(old);
		std::string allMessages = buffer.str();
		std::stringstream msgStream(allMessages);
		std::string firstLine;
		std::getline(msgStream, firstLine);
		int attackCount = 0;
		std::string line;
		while (std::getline(msgStream, line) && attackCount <= y) {
			if (line.find("Not enough energy points") != std::string::npos)
				break;
			attackCount++;
		}
		std::cout << firstLine << std::endl;
		std::cout << "... (" << attackCount << " attaques supplémentaires)" << std::endl;
		if (!line.empty())
			std::cout << line << std::endl;
		frag6.beRepaired(10);
	}

	std::cout << "\n--- end of tests ---" << std::endl;
	return 0;
}
