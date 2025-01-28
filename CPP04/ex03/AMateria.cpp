#include "AMateria.hpp"

AMateria::AMateria()
{

}

AMateria::AMateria(std::string const &type)
{
    mat_type = type;
}

AMateria::AMateria(const AMateria &source)
{
	*this = source;
}

AMateria &AMateria::operator=(const AMateria &source)
{
    mat_type = source.mat_type;
    return(*this);
}

void	AMateria::use(ICharacter &target)
{
	target.getName();
}

AMateria::~AMateria()
{

}

std::string const &AMateria::getType()const
{
    return (mat_type);
}
