#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <iostream>

class ClapTrap
{
private:
    std::string name;
    int         hp;
    int         en;
    int         ap;

public:
    ClapTrap();
    ClapTrap(ClapTrap &);
    ClapTrap &operator=(const ClapTrap&);
    ~ClapTrap();
    ClapTrap(std::string);
    void    attack(const std::string &target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
};

#endif
