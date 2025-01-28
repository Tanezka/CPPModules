#ifndef CURE_H
# define CURE_H
# include "AMateria.hpp"

class Cure: public AMateria
{
protected:

public:
    Cure();
    Cure(const Cure&);
    Cure &operator=(const Cure&);
    ~Cure();
    void	use(ICharacter &);
    AMateria *clone() const;
};
#endif
