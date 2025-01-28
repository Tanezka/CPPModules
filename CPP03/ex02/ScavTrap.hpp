#ifndef SCAVTRAP_H
# define SCAVTRAP_H
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
private:

public:
    ScavTrap();
    ScavTrap(std::string);
    ScavTrap(ScavTrap &source);
    ScavTrap    &operator=(const ScavTrap&);
    void    attack(std::string);
    ~ScavTrap();
    void    guardGate();
};
#endif
