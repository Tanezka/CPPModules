#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <stdexcept>

int main(void)
{
	AForm					*testForm;
	try
	{
		Intern					Lale;
    	Bureaucrat				Burhan("Burhan", 1);
		
		testForm = Lale.makeForm("robotomy request", "robo");
		Burhan.signAForm(*testForm);
    	Burhan.executeForm(*testForm);
	}

	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete testForm;
}
