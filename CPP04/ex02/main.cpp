#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

int main()
{
    Animal  *array[100];
    int     i;

    i = -1;
    while (++i < 100)
    {
        if (i % 2 == 1)
            array[i] = new Cat();
        else
            array[i] = new Dog();
    }
    i--;
    array[2]->makeSound();
    while (i >= 0)
    {
        delete array[i];
        i--;
    }
    return 0;
}
