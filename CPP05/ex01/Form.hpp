#ifndef FORM_H
# define FORM_H
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class   Bureaucrat;

class   Form
{
private:
        const		std::string name;
        bool		is_signed;
        const int	sign_grade;
        const int	exec_grade;
public:
        class GradeTooHighException : public std::exception
        {
            virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            virtual const char *what() const throw();
        };
        Form();
        Form(std::string name, int sign_grade, int exec_grade);
        Form(const Form &source);
        Form &operator=(const Form &source);
        std::string     getName() const;
        bool            getSigned() const;
        int             getSignGrade() const;
        int             getExecGrade() const;
        bool            beSigned(Bureaucrat &person);
        ~Form();
};

std::ostream& operator<<(std::ostream& os, const Form& obj);
#endif
