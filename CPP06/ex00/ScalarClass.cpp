#include "ScalarClass.hpp"
#include <iostream>
#include <limits.h>
#include <sstream>
#include <math.h>

bool	my_isalp(char tmp)
{
	if ((tmp >= 'a' && tmp <= 'z') || (tmp >= 'A' && tmp<='Z'))
		return(true);
	return(false);
}

void ScalarConverter::convert (char* tmp)
{
    double  temp;
	if (my_isalp(tmp[0]) && !tmp[1])
		temp = static_cast<double>(tmp[0]);	
	else
    	temp = atof(tmp);
    std::cout.precision(1);
    std::cout << std::fixed;
    ScalarConverter::convert_char(temp);   
    ScalarConverter::convert_int(temp);   
    ScalarConverter::convert_float(temp);   
    std::cout << "double: " << temp << "\n";
}

void ScalarConverter::convert_int(double tmp)
{
    int         nbr;
    
    std::cout << "int: ";
    if (tmp != tmp || tmp < INT_MIN || tmp > INT_MAX)
    {
        std::cout << "literally impossible\n";
        return;
    }
    nbr = static_cast<int>(tmp);
    std::cout << nbr << "\n";
}

void ScalarConverter::convert_float(double tmp)
{
    float           nbr;

    nbr = static_cast<float>(tmp);
    std::cout << "float: " << nbr << "f\n";
}

void ScalarConverter::convert_char(double tmp)
{
    char         nbr;
    
    std::cout << "char: ";
    if (tmp != tmp || !isascii(tmp))
    {
        std::cout << "literally impossible\n";
        return;
    }
    else if (!isprint(tmp))
    {
        std::cout << "non displayable\n";
        return;
    }
    nbr = static_cast<char>(tmp);
    std::cout << "'" << nbr << "'" << "\n";
}

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &tmp)
{
	(void)tmp;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &source)
{
	(void)source;
	return (*this);
}
