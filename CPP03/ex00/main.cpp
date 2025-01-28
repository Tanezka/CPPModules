#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap boi("boi");
    ClapTrap dayum("dayum");
    
    boi.attack("dayum");
    boi.takeDamage(2);
    boi.attack("dayum");
    boi.takeDamage(2);
    boi.attack("dayum");
    boi.takeDamage(2);
    boi.beRepaired(2);
    boi.attack("dayum");
    boi.takeDamage(2);
    boi.beRepaired(2);
    boi.beRepaired(2);
    boi.beRepaired(2);
    boi.beRepaired(2);
    ClapTrap temp(boi);
    temp.attack("boi");
    boi.beRepaired(2);
    boi.attack("dayum");
    boi.beRepaired(2);
    boi.takeDamage(200);
    boi.beRepaired(2);
    boi.attack("dayum");
}
