#include "Ice.hpp"

Ice::Ice()
{
	mat_type = "ice";
}

Ice::Ice(const Ice &source)
{
	*this = source;
}
    
void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

Ice &Ice::operator=(const Ice &source)
{
	this->mat_type = source.mat_type;
    return (*this);
}

Ice::~Ice()
{

}

AMateria *Ice::clone() const
{
    AMateria *temp = new Ice();
    return (temp);
}
