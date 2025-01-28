#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

int	main(void)
{
	std::string	temp;
	Weapon		sword("Broadsword");
	Weapon		hammer("Great hammer");
	HumanA		Josh("Josh", sword);
	HumanB		Jacop("Jacop");
	
	Jacop.setWeapon(hammer);
	sword.setType("Claymore");
	temp = sword.getType();
	
	std::cout << temp << " and " << hammer.getType() << "\n";
	
	Josh.attack();
	Jacop.attack();

	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();

	Weapon club1 = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club1);
	jim.attack();
	club1.setType("some other type of club");
	jim.attack();
}
