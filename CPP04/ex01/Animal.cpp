#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal const\n";
}

Animal::Animal(std::string str):type(str)
{
    std::cout << "Animal const\n";
}

Animal::Animal(const Animal &source)
{
    std::cout << "Animal copy const\n";
    *this = source;
}

Animal    &Animal::operator=(const Animal &source)
{
    std::cout << "Animal \"=\" operator\n";
    this->type = source.type;
    return (*this);
}

void    Animal::makeSound() const
{

}

std::string Animal::getType() const
{
    return (type);
}

Animal::~Animal()
{

}
