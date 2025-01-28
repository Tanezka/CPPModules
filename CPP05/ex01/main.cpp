#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <stdexcept>

int main(void)
{
    try
    {
    	Bureaucrat test1("Burhan", 65);
        Form        patates("Evlilik", 62, 3);
        std::cout << patates << "\n";
        test1.signForm(patates);
    }

    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
