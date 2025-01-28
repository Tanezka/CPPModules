#ifndef AFORM_H
# define AFORM_H
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class   Bureaucrat;

class   AForm
{
protected:
            const		std::string name;
            const		std::string target;
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
        class FormUnsignedException : public std::exception
        {
            virtual const char *what() const throw();
        };

        AForm();
        AForm(std::string name, std::string target, int sign_grade, int exec_grade);
        AForm(const AForm &source);
        AForm &operator=(const AForm &source);
        virtual void	conc_execute() const = 0;
        bool            execute(Bureaucrat const & executor) const;
        std::string     getName() const;
        std::string     getTarget() const;
        bool            getSigned() const;
        int             getSignGrade() const;
        int             getExecGrade() const;
        bool            beSigned(Bureaucrat &person);
        virtual			~AForm();
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);
#endif
