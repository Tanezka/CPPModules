#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string myname, Weapon &myWeapon): name(myname), weapon(myWeapon)
{

}

HumanA::~HumanA()
{

}
void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << "\n";
}
