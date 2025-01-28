#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <stdexcept>

Bureaucrat::Bureaucrat()
{

}

Bureaucrat::Bureaucrat(std::string str, int grade): name(str), grade(grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &source)
{
    *this = source;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &source)
{
    if (source.grade)
        this->grade = source.grade;
    return (*this);
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() 
{
	return "Bureaucrat grade too low!";
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() 
{
	return "Bureaucrat grade too high!";
}

void    Bureaucrat::signForm(Form   &myform)
{
    if (myform.beSigned(*this))
    {
        std::cout << name << " signed " << myform.getName() << "." << std::endl;
    }
    else
        std::cout << name << " couldn't sign the form: " << myform.getName() << ". Because their grade is too low." << std::endl;
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

std::ostream & operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return (os);
}

void    Bureaucrat::increment()
{
    this->grade -= 1;
	if (this->grade < 1)
        throw GradeTooHighException();
}

void    Bureaucrat::decrement()
{
    this->grade += 1;
	if (this->grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{

}
