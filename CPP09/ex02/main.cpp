#include <iostream>
#include <vector>
#include <list>
#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	int			i = -1;
    Pmergeme	merge;
	std::string	str;

    if (ac < 2)
        return 0;
    av++;
	while (ac > 2 && av[++i])
	{
		if (static_cast<int>(std::strtoul(av[i], NULL, 10)) < 0)
		{
			std::cout << "Error\n";
			return 0; 
		}
	}
	if (ac == 2)
	{
		str = av[0];
		if (str.find('-') != std::string::npos)
		{
			std::cout << "Error\n";
			return 0; 
		}
	}
    if (merge.merge_insert(av))
		std::cout << "Error\n";
	//Pmergeme	test(merge);
    //test.merge_insert(av);
	return 0;
}
