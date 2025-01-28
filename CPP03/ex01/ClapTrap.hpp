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
    ClapTrap(std::string);
    ClapTrap(ClapTrap &);
    ClapTrap &operator=(const ClapTrap&);
    ~ClapTrap();
    int     get_attack() const;
    int     get_health() const;
    int     get_energy() const;
    std::string     get_name() const;
    void    set_attack(int);
    void    set_health(int);
    void    set_energy(int);
    void    set_name(std::string);
    void    attack(const std::string &target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
};

#endif
