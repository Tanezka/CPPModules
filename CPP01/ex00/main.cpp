#include "Zombie.hpp"

int main(void)
{
    Zombie  *zombie1 = newZombie(std::string("selami"));
    zombie1->announce();
    randomChump(std::string("dilsad"));
    delete zombie1;
}
