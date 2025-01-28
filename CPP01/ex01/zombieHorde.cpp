#include "Zombie.hpp"
#include <iostream>
#include <sstream>

Zombie *zombieHorde( int N, std::string name )
{
	std::stringstream test;
    int	i;

    i = -1;
    Zombie *zom = new Zombie[N];
    while (++i < N)
	{
		test << i + 1;
        new (&zom[i]) Zombie(name + test.str());
		test.str("");
	}
    return (zom);
}
