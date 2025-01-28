#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructer has been called\n";
	this->fixed_point = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructer\n";
	fixed_point = num * 256; //2^8 = 256
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructer\n";
	fixed_point = static_cast<int>(roundf(num * 256)); //2^8 = 256
}

float	Fixed::toFloat(void) const
{
	float	temp;
	
	temp = static_cast<float>(fixed_point) / 256; //2^8 = 256
	return(temp);
}

int		Fixed::toInt(void) const
{
	int	temp;

	temp = fixed_point / 256; //2^8 = 256
	return(temp);

}

Fixed::Fixed(const Fixed &source)
{
	std::cout << "Copy constructer has been called\n";
	*this = source;
}

Fixed &Fixed::operator=(const Fixed &source)
{
	std::cout << "Copy assignment operator been called\n";
	if (this != &source)
	{
		this->fixed_point = source.fixed_point;
	}
	return (*this);
}


std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	float num;
	num = obj.toFloat();
	os << num;
	return (os);
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

