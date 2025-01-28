#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB()
{

}

HumanB::~HumanB()
{

}

HumanB::HumanB(std::string myname): name(myname)
{

}
void	HumanB::attack(void)
{
	std::cout << name << " attacks with their ";
	std::cout << weapon->getType();
	std::cout << "\n";
}

void	HumanB::setWeapon(Weapon &myWeapon)
{
	weapon = &myWeapon;
}
