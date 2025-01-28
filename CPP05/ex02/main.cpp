#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <stdexcept>

int main(void)
{
	try
	{
    	Bureaucrat Burhan("Burhan", 1);
    	Bureaucrat Mahmut("Mahmut", 150);
    	RobotomyRequestForm form1("Murat");
		ShrubberyCreationForm form2("patates");
    	PresidentialPardonForm form3 ("başkanyalakasi");
    	
    	//Burhan.executeForm(form1);
		Burhan.signAForm(form1);
		Burhan.signAForm(form2);
		Burhan.signAForm(form3);
    	//Mahmut.executeForm(form1);
    	Burhan.executeForm(form1);
    	//Burhan.executeForm(form2);
    	Burhan.executeForm(form3);
	}

	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    
}
