#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class   Dog : public Animal
{
private:
    Brain   *dog_brain;
protected:

public:
    void    makeSound() const;
    Dog();
    Dog(const Dog&);
    Dog  &operator=(const Dog&);
    ~Dog();
};
#endif
