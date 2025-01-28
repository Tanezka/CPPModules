#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap bo("bo");
    ScavTrap lo("lo");
    
    bo.attack("lo");
    lo.takeDamage(bo.get_attack());
	lo.beRepaired(7);
    bo.guardGate();
}
