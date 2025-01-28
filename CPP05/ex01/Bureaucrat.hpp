#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H
# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Form;

class Bureaucrat
{
private:
        const	std::string name;
        int		grade;
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
        void    signForm(Form   &myform);
        ~Bureaucrat();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);
#endif
