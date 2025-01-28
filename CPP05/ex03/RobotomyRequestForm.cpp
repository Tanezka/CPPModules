#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string Target): AForm("RobotomyRequestForm", Target, 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form): target(form.target)
{
	*this = form;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &source)
{
	source.getName();
    return (*this);
}

void RobotomyRequestForm::conc_execute() const
{
    int random;

    srand(time(NULL));
    random = rand() % 2; 
    std::cout << "BRRZZRZRZRZTRZRT!" << std::endl;
    if (random % 2 == 1)
        std::cout << this->getTarget() << " has been robotomized\n";
    else
        std::cout << "Robotomy has been failed\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}
