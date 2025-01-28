#include "ClapTrap.hpp"
    
ClapTrap::ClapTrap()
{
    std::cout << "Clap Default const\n";
    hp = 10;
    en = 10;
    ap = 0;
}

ClapTrap::ClapTrap(std::string str): name(str)
{
    std::cout << "Clap Default const\n";
    hp = 10;
    en = 10;
    ap = 0;
}

ClapTrap::ClapTrap(ClapTrap &source)
{
    std::cout << "Clap Copy const\n";
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

int     ClapTrap::get_attack() const
{
    return(ap);
}

int     ClapTrap::get_health() const
{
    return(hp);
}

int     ClapTrap::get_energy() const
{
    return (en);
}
 
std::string ClapTrap::get_name() const
{
    return (name);
}

void    ClapTrap::set_attack(int temp)
{
    ap = temp;
}
 
void    ClapTrap::set_health(int temp)
{
    hp = temp;
}
  
void    ClapTrap::set_energy(int temp)
{
    en = temp;
}

void    ClapTrap::set_name(std::string temp)
{
    name = temp;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Clap Destruction\n";
}

void    ClapTrap::attack(const std::string &target)
{
    if (en > 0 && hp > 0)
    {
        en--;
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << ap << " points of damage!\n";
    }
    else if (hp <= 0)
        std::cout << name << " is D E A D \n";
    else
        std::cout << name << " has no energy\n";
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    hp -= amount;
    std::cout << name << " has been hit for " << amount << "\n";
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (en > 0 && hp > 0)
    {
        hp += amount;
        en--;
        std::cout << name << " has repaired itself for " << amount << "\n";
    }
    else if (hp <= 0)
        std::cout << name << " is D E A D \n";
    else
        std::cout << name << " has no energy\n";
}
