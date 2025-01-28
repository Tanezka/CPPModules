#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

AForm::AForm():name(""), sign_grade(150), exec_grade(150)
{

}

AForm::AForm(std::string str, std::string Target, int signGrade, int execGrade): name(str), target(Target), is_signed(false), sign_grade(signGrade), exec_grade(execGrade)
{
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
}

AForm::AForm(const AForm &source):name(source.name), target(source.target), is_signed(source.is_signed), sign_grade(source.sign_grade), exec_grade(source.exec_grade)
{

}

AForm &AForm::operator=(const AForm &source)
{
    this->is_signed = source.is_signed;

    return (*this);
}

std::string AForm::getName() const
{
    return (this->name);
}

bool    AForm::getSigned() const
{
    return (is_signed);
}

int AForm::getSignGrade() const
{
    return (sign_grade);
}

int AForm::getExecGrade() const
{
    return (exec_grade);
}
std::string     AForm::getTarget() const
{
    return (target);
}

bool	AForm::beSigned(Bureaucrat &person)
{
    if (person.getGrade() <= sign_grade)
        is_signed = true;
	return (is_signed);
}

const char*	AForm::GradeTooLowException::what() const throw()
{
    return("Form grade is too low");
}

const char*	AForm::GradeTooHighException::what() const throw()
{
    return("Form grade is too high");
}

const char*	AForm::FormUnsignedException::what() const throw()
{
    return ("Form is unsigned");
}

bool	AForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getExecGrade())
        throw GradeTooHighException();
    if (this->getSigned() != true)
        throw FormUnsignedException();
    conc_execute();
	return (true);
}
std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
    std::string sign;

    if (obj.getSigned() == true)
        sign = "Signed";
    else
        sign = "Not signed";
    os << "Aform name: " << obj.getName() << "\nIs form signed: " << sign << "\nForm sign grade: " << obj.getSignGrade() << "\nAForm execution grade: " << obj.getExecGrade() << std::endl;
    return (os);
}
AForm::~AForm()
{

}
