#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain Def const\n";
}
    
Brain::Brain(const Brain &source)
{
    std::cout << "Brain copy const\n";
    *this = source;
}
    
Brain &Brain::operator=(const Brain &source)
{
    int i = -1;

    std::cout << "Brain \"=\" overload\n";
    while(++i < 100)
        ideas[i] = source.ideas[i];
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain has been destroyed\n";
}
