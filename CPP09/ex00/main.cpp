#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char** av) 
{
    if (ac != 2)
        return 0;
    Bitcoin data(av[1]);
    data.fill_map();
}
