#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern;

typedef AForm* (Intern::*fpointer)(const std::string&) const;

class Intern 
{
private:
		static const std::string	names[3];
		static const fpointer		forms[3];

		AForm*	ShrubberyCreation(const std::string &target) const;
		AForm*	RobotomyRequest(const std::string &target) const;
		AForm*	PresidentialPardon(const std::string &target) const;
public:
		Intern();
		~Intern();
		Intern(const Intern &other);
		Intern	&operator=(const Intern &other);
		AForm*	makeForm(const std::string &form, const std::string &target) const;
		class FormNotFoundException: public std::exception 
		{
			virtual const char*	what() const throw();
		};
};

#endif
