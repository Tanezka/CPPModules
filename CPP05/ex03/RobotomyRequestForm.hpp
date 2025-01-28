#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
        const std::string target;

public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &source);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &source);
        ~RobotomyRequestForm();
        void    conc_execute() const;
};
#endif
