#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class   Animal
{
private:

protected:
    std::string type;
public:
    Animal();
    Animal(std::string);
    Animal(const Animal&);
    virtual void    makeSound() const = 0;
    Animal  &operator=(const Animal&);
    std::string getType()const;
    virtual ~Animal();
};

#endif
