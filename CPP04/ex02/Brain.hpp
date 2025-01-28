#ifndef BRAIN_H
# define BRAIN_H
# include <string>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    Brain(const Brain&);
    Brain &operator=(const Brain&);
    ~Brain();
};

#endif
