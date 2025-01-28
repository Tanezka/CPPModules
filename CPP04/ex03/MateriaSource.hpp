#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *mat_array[4];
public:
    MateriaSource();
    MateriaSource(const MateriaSource&);
    MateriaSource &operator=(const MateriaSource&);
    ~MateriaSource();
    void    learnMateria(AMateria*);
    AMateria *createMateria(std::string const & type);
};
#endif
