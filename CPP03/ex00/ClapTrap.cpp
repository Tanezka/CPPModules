#include "ClapTrap.hpp"
    
ClapTrap::ClapTrap()
{
    std::cout << "Default const\n";
    hp = 10;
    en = 10;
    ap = 0;
}

ClapTrap::ClapTrap(std::string str): name(str)
{
    std::cout << "Default const\n";
    hp = 10;
    en = 10;
    ap = 0;
}

ClapTrap::ClapTrap(ClapTrap &source)
{
    std::cout << "Copy const\n";
    *this = source;
}

ClapTrap &ClapTrap::operator=(const ClapTrap&source)
{
    this->name = source.name;
    this->hp = source.hp;
    this->en = source.en;
    this->ap = source.ap;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destruction\n";
}

void    ClapTrap::attack(const std::string &target)
{
    if (en > 0 && hp > 0)
    {
        en--;
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << ap << " points of damage!\n";
    }
    else if (hp <= 0)
        std::cout << "ClapTrap " << name << " is D E A D \n";
    else
        std::cout << "ClapTrap " << name << " has no energy\n";
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    hp -= amount;
    std::cout << "ClapTrap " << name << " has been hit for " << amount << "\n";
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (en > 0 && hp > 0)
    {
        hp += amount;
        en--;
        std::cout << "ClapTrap " << name << " has repaired itself for " << amount << "\n";
    }
    else if (hp <= 0)
        std::cout << "ClapTrap " << name << " is D E A D \n";
    else
        std::cout << "ClapTrap " << name << " has no energy\n";
}
