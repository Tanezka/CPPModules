#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

int main(void)
{
	try
	{
    	Bureaucrat test("Burhan", 11);
    	std::cout << test << std::endl;
		test.increment();
		std::cout << test.getName() << "'s grade is: " << test.getGrade() << std::endl;
		test.decrement();
		std::cout << test.getName() << "'s grade is: " << test.getGrade() << std::endl;
	}
	
	catch(std::exception &e)
	{
        std::cout << e.what() << std::endl;
	}
    try
    {
        Bureaucrat test("Fatih", 1);
		test.increment();
    	std::cout << test << std::endl;
    }

    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
