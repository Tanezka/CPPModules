#include "Intern.hpp"
#include <iostream>

const std::string	Intern::names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
const fpointer		Intern::forms[3] = {&Intern::ShrubberyCreation, &Intern::RobotomyRequest, &Intern::PresidentialPardon};

Intern::Intern()
{

}

Intern::~Intern()
{

}

Intern::Intern(const Intern &tmp)
{
	*this = tmp;
}

Intern &Intern::operator=(const Intern &tmp)
{
	(void)tmp;
	return (*this);
}

AForm*	Intern::ShrubberyCreation(const std::string& target) const 
{
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::RobotomyRequest(const std::string& target) const 
{
	return new RobotomyRequestForm(target);
}

AForm*	Intern::PresidentialPardon(const std::string& target) const 
{
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(const std::string& form, const std::string& target) const 
{
	int i;

	i = -1;
	while (++i < 3)
	{
		if (names[i] == form)
		{
			std::cout << "Intern creates " << names[i] << " form.\n";
			return (this->*(forms[i]))(target);
		}
	}
	throw FormNotFoundException();
}

const char*	Intern::FormNotFoundException::what() const throw() 
{
	return "<Intern> Form not found!";
}
