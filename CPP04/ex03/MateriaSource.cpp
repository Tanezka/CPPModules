#include "MateriaSource.hpp"
#include <cctype>

MateriaSource::MateriaSource()
{
	int	i = -1;

	while(++i < 4)
		mat_array[i] = nullptr;
}
    
MateriaSource::MateriaSource(const MateriaSource &source)
{
    std::cout << "MateriaSource copy const\n";
    *this = source;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &source)
{
	int	i;

	i = -1;
	while(++i < 4)
		this->mat_array[i] = source.mat_array[i];
    return(*this);
}

MateriaSource::~MateriaSource()
{
	int	i;

	i = -1;
	while(++i < 4)
	{
		if (mat_array[i] != nullptr)
			delete mat_array[i];
	}
}

void    MateriaSource::learnMateria(AMateria* mat)
{
	int i;

	i = -1;
	while (mat_array[++i] != nullptr);
	if (i < 4)
		mat_array[i] = mat;
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
	int i;
	std::string my_type(type);

	i = -1;
	while (++i < 4 && (my_type.compare("ice") == 0 || my_type.compare("cure") == 0))
	{
		if (mat_array[i]->getType().compare(my_type) == 0 || mat_array[i]->getType().compare(my_type) == 0)
			return (mat_array[i]->clone());
	}
    return (0);
}
