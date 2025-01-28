#include "Character.hpp"

Character::Character(std::string str):name(str)
{
	int	i;

	i = -1;
	dump = new AMateria*[1];
	dump[0] = nullptr;
	while (++i < 4)
		inventory[i] = nullptr;
}

std::string const &Character::getName() const
{
	return (name);
}

Character::Character(const Character &source)
{
	*this = source;
}
	
Character &Character::operator=(const Character &source)
{
	int i;

	i = -1;
	while (++i < 4)
		this->inventory[i] = source.inventory[i]->clone();
	this->name = source.name;
	return (*this);
}

void Character::equip(AMateria* m)
{
	int	i;

	i = -1;
	while (++i < 4 && inventory[i] != m);
	if (i != 4)
	{
		std::cout << "This mat has already in inventory\n";
		return ;
	}
	i = -1;
	while (dump[++i] != nullptr)
	{
		if (m == dump[i])
		{
			std::cout << "This item is on floor you cant equip it! \n";
			return ;
		}
	}
	i = -1;
	while(++i < 4 && inventory[i] != nullptr);
	if (i < 4)
		inventory[i] = m;
}
    
void Character::unequip(int idx)
{
	long long	index;
	static long long max = 2;
	if (inventory[idx] == nullptr)
		return ;
	AMateria **temp = new AMateria*[max];
	index = -1;
	while (++index < max - 1)
	{
		if (dump[index] == nullptr)
		{
			dump[index] = inventory[idx];
			inventory[idx] = nullptr;
		}
		temp[index] = dump[index];
	}
	temp[index] = nullptr;
	delete[] dump;
	dump = temp;
	max++;
}

void Character::use(int idx, ICharacter& target)
{
	if (inventory[idx] != nullptr)
	{
		inventory[idx]->use(target);
	}
}

Character::~Character()
{
	int i;

	i = -1;
	while(++i < 4)
		if (inventory[i] != nullptr)
			delete inventory[i];
	i = -1;
	while (dump[++i] != nullptr)
		delete dump[i];
	delete[] dump;
}	
