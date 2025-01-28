#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog const\n";
}

Dog::Dog(const Dog &source):Animal(source)
{
    std::cout << "Dog copy const\n";
    *this = source;
}

Dog    &Dog::operator=(const Dog &source)
{
    std::cout << "Dog \"=\" operator\n";
    this->type = source.type;
    return (*this);
}

void    Dog::makeSound()const
{
    std::cout << "Woof\n";
}

Dog::~Dog()
{

}
