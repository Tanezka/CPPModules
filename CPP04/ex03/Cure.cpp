#include "Cure.hpp"

Cure::Cure()
{
	mat_type = "cure";
}
    
Cure::Cure(const Cure &source)
{
	*this = source;
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}
Cure &Cure::operator=(const Cure &source)
{
	this->mat_type = source.mat_type;
    return (*this);
}

Cure::~Cure()
{

}

AMateria *Cure::clone() const
{
    AMateria *temp = new Cure();
    return (temp);
}
