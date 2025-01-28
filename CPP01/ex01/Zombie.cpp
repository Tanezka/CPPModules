#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{

}
Zombie::Zombie(std::string nm) : name(nm)
{

}

void	Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie()
{
    std::cout << name << " has been destroyed\n";
}
        
