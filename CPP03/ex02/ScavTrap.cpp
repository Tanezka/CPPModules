#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "Scav const\n";
    set_health(100);
    set_energy(50);
    set_attack(20);
}

ScavTrap::ScavTrap(std::string str)
{
    std::cout << "Scav const\n";
    set_name(str);
    set_health(100);
    set_energy(50);
    set_attack(20);
}

ScavTrap::ScavTrap(ScavTrap &source): ClapTrap(source)
{
    std::cout << "Scav copy const\n";
    *this = source;
}
    
ScavTrap &ScavTrap::operator=(const ScavTrap &source)
{
    set_name(source.get_name());
    set_health(source.get_health());
    set_energy(source.get_energy());
    set_attack(source.get_attack());
    return (*this);
}

void    ScavTrap::attack(std::string target)
{
	if (get_health() > 0 && get_energy() > 0)
	{
    	std::cout << "ScavTrap " << get_name() << " attacks " << target << ", causing " << get_attack() << " points of damage!\n";
		set_energy(get_energy() - 1);
	}
    else if (get_health ()<= 0)
        std::cout << get_name() << " is D E A D \n";
    else
        std::cout << get_name() << " has no energy\n";
}

void    ScavTrap::guardGate()
{
	if (get_health() > 0)
    	std::cout << "ScavTrap " << get_name() << " is now in gatekeeper mode\n";
    else if (get_health ()<= 0)
        std::cout << get_name() << " is D E A D \n";
}
ScavTrap::~ScavTrap()
{
    std::cout << "Scav destr\n";
}
