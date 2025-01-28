#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
private:
        const std::string target;

public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &source);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &source);
        ~ShrubberyCreationForm();
        void    conc_execute() const;
};
#endif
