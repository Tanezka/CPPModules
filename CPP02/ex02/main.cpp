#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
	Fixed q;
	Fixed const e( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << q << std::endl;
	std::cout << ++q << std::endl;
	std::cout << q << std::endl;
	std::cout << q++ << std::endl;
	std::cout << q << std::endl;
	std::cout << e << std::endl;
	std::cout << Fixed::max( q, e ) << std::endl;

	Fixed a(5.05f);
	Fixed b(2);

    std::cout << "A is: " << a << " B is : " << b << "\n";
    if (a < b)
        std::cout << "A is smaller\n";
    if (a > b)
        std::cout << "B is smaller\n";
    if (a <= b)
        std::cout << "A is equal or smaller\n";
    if (a >= b)
        std::cout << "B is equal or smaller\n";
    if (a == b)
        std::cout << "A and B are equal\n";
    if (a != b)
    {
        std::cout << "A and B are not equal\n";
    }
	std::cout << "Sum: "<< a + b << "\n";
	std::cout << "Minus: " << a - b << "\n";
	std::cout << "Divide: " << a / b << "\n";
	std::cout << "Times: " << a * b << "\n";
	std::cout << "Min: " << Fixed::min(a, b) << "\n";
	std::cout << "Max: " << Fixed::max(a, b) << "\n";
	std::cout << "before " << a++ << " after " << a << "\n";
	std::cout << "before " << a << " after " << ++a << "\n";
	std::cout << "before " << b << " after " << --b << "\n";
	std::cout << "before " << b-- << " after " << b << "\n";

	return 0;
}
