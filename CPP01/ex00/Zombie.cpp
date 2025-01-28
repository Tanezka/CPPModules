#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{

}

Zombie::Zombie(std::string str): name(str)
{

}

Zombie::~Zombie()
{
    std::cout << name << " Has been D E S T R U C T E D\n";
}

void    Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
