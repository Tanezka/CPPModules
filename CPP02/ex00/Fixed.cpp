#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Default constructer has been called\n";
	this->fixed_point = 0;
}

Fixed::Fixed(Fixed &source)
{
	std::cout << "Copy constructer has been called\n";
	*this = source;
}

Fixed &Fixed::operator=(const Fixed &source)
{
	std::cout << "Copy assignment operator been called\n";
	if (this != &source)
	{
		this->fixed_point = source.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "D E S T R U C T E R has been called\n";
}

int		Fixed::getRawBits(void) const
{
	std::cout << "Get raw has been called\n";
	return (fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "Set raw has been called\n";
	fixed_point = raw;
}

