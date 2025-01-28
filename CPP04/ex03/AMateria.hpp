#ifndef AMATERIA_H
# define AMATERIA_H
# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
protected:
    std::string mat_type;

public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(const AMateria&);
	virtual AMateria &operator=(const AMateria&);
    virtual ~AMateria();
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};
#endif
