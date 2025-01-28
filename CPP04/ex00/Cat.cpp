#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat const\n";
}

Cat::Cat(const Cat &source):Animal(source)
{
    std::cout << "Cat copy const\n";
    *this = source;
}

Cat    &Cat::operator=(const Cat &source)
{
    std::cout << "Cat \"=\" operator\n";
    this->type = source.type;
    return (*this);
}

void    Cat::makeSound()const
{
    std::cout << "Meowwwwww ^*-*^\n";
}

Cat::~Cat()
{

}
