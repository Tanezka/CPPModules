#include <iostream>

void    converter (char *str)
{
    int i;

    i = -1;
    while (str[++i])
    {
        str[i] = std::toupper(str[i]);
    }
}

int main (int ac, char **av)
{
    int i;
    
    i = 0;
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    while (!!(av[++i]))
    {
        converter(av[i]);
        std::cout << av[i];
    }
    std::cout << std::endl;
}
/*
*
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
*/
