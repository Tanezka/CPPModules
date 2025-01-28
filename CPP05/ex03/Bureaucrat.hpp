#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H
# include <iostream>
# include <stdexcept>
# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
        const   std::string name;
        int         grade;
public:
        class GradeTooHighException : public std::exception
        {
            virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            virtual const char *what() const throw();
        };
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &source);
        Bureaucrat &operator=(const Bureaucrat &source);
        std::string  getName() const;
        int     getGrade() const;
        void    increment();
        void    decrement();
        void    signAForm(AForm   & myform);
        void    executeForm(AForm const & form);
        ~Bureaucrat();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);
#endif
