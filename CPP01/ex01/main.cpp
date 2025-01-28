#include "Zombie.hpp"
#include <iostream>

int main(int ac, char **av)
{
    Zombie 	*zom;
	int		num;
	int		i;

	i = -1;
	if (ac == 2)
	{
		num = std::atoi(av[1]);
		if (num > 0)
		{
    		zom = zombieHorde(num, "tak");
			while (++i < num)
				zom[i].announce();
    		delete[] zom;
			return (0);
		}
	}
	std::cout << "Bad input\n";
	return (0);
}
