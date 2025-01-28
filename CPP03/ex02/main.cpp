#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    FragTrap bo("bo");
    FragTrap lo("lo");
    
    bo.attack("dayum");
    bo.takeDamage(2);
    bo.attack("villager");
    bo.highFivesGuys();
}
