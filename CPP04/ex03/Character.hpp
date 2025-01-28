#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
private:
    AMateria *inventory[4];
	std::string name;
	AMateria **dump;
public:
    Character(std::string);
	Character(const Character&);
	Character &operator=(const Character&);
    ~Character();
    std::string const & getName() const;
    void unequip(int idx);
    void use(int idx, ICharacter& target);
    void equip(AMateria* m);
};

#endif
