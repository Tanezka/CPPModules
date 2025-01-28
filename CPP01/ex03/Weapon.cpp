#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon()
{

}

Weapon::~Weapon()
{
	delete type;
}

Weapon::Weapon(std::string str)
{
	type = new std::string (str);
}
 
const std::string&	 Weapon::getType(void)
{
	const std::string &ref = *type;
	return((ref));
}
void	Weapon::setType(std::string str)
{
	if (type->length() != 0)
		delete type;
	type = new std::string (str);
}
