#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "Frag const\n";
    set_health(100);
    set_energy(100);
    set_attack(30);
}

FragTrap::FragTrap(std::string str)
{
    std::cout << "Frag const\n";
    set_name(str);
    set_health(100);
    set_energy(100);
    set_attack(30);
}

FragTrap::FragTrap(FragTrap &source): ClapTrap(source)
{
    std::cout << "Frag copy const\n";
    *this = source;
}
    
FragTrap &FragTrap::operator=(const FragTrap &source)
{
    set_name(source.get_name());
    set_health(source.get_health());
    set_energy(source.get_energy());
    set_attack(source.get_attack());
    return (*this);
}

void    FragTrap::attack(std::string target)
{
	if (get_health() > 0 && get_energy() > 0)
	{
    	std::cout << "FragTrap " << get_name() << " attacks " << target << ", causing " << get_attack() << " points of damage!\n";
		set_energy(get_energy() - 1);
	}
    else if (get_health() <= 0)
        std::cout << get_name() << " is D E A D \n";
    else
        std::cout << get_name() << " has no energy left\n";
}

void    FragTrap::highFivesGuys()
{
	if (get_health() > 0)
   		std::cout << "FragTrap " << get_name() << " wants to highfive! So exciting!\n";
    else if (get_health() <= 0)
        std::cout << get_name() << " is D E A D \n";
}
FragTrap::~FragTrap()
{
    std::cout << "Frag destr\n";
}
