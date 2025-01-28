#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
        const std::string target;

public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &source);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &source);
        ~PresidentialPardonForm();
        void    conc_execute() const;
};
#endif
