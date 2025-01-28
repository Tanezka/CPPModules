#ifndef FRAGTRAP_H
# define FRAGTRAP_H
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
private:

public:
    FragTrap();
    FragTrap(std::string);
    FragTrap(FragTrap &source);
    FragTrap    &operator=(const FragTrap&);
    void    attack(std::string);
    ~FragTrap();
    void    highFivesGuys(void);
};
#endif
