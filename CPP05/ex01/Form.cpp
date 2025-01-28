#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

Form::Form():name("") ,sign_grade(150), exec_grade(150)
{

}

Form::Form(std::string str, int signGrade, int execGrade): name(str), is_signed(false), sign_grade(signGrade), exec_grade(execGrade)
{
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
}

Form::Form(const Form &source):name(source.name), is_signed(source.is_signed), sign_grade(source.sign_grade), exec_grade(source.exec_grade)
{

}

Form &Form::operator=(const Form &source)
{
    this->is_signed = source.is_signed;

    return (*this);
}

std::string Form::getName() const
{
    return (this->name);
}

bool    Form::getSigned() const
{
    return (is_signed);
}

int Form::getSignGrade() const
{
    return (sign_grade);
}

int Form::getExecGrade() const
{
    return (exec_grade);
}

bool	Form::beSigned(Bureaucrat &person)
{
    if (person.getGrade() <= sign_grade)
        is_signed = true;
	return (is_signed);
}

const char*	Form::GradeTooLowException::what() const throw()
{
    return("Form grade is too low");
}

const char*	Form::GradeTooHighException::what() const throw()
{
    return("Form grade is too high");
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    std::string sign;

    if (obj.getSigned() == true)
        sign = "Signed";
    else
        sign = "Not signed";
    os << "Form name: " << obj.getName() << "\nIs form signed: " << sign << "\nForm sign grade: " << obj.getSignGrade() << "\nForm execution grade: " << obj.getExecGrade();
    return (os);
}
Form::~Form()
{

}
