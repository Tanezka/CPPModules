#include <iostream>
#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
	{
        std::cout << "Error" << "\n";
        return 0;
	}
    Rpn         tmp;
    int answer = tmp.operations(av[1]);
    if (answer == 1)
        std::cout << "Error" << "\n";
    return 0;
}
