#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	this->fixed_point = 0;
}

Fixed::Fixed(const int num)
{
	fixed_point = num * 256; //2^8 = 256
}

Fixed::Fixed(const float num)
{
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
	*this = source;
}

Fixed &Fixed::operator=(const Fixed &source)
{
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

bool    Fixed::operator<(const Fixed &source) const
{
    if (this->fixed_point < source.fixed_point)
	    return (true);
    return(false);
}

bool    Fixed::operator>(const Fixed &source) const
{
    if (this->fixed_point > source.fixed_point)
	    return (true);
    return(false);
}

bool    Fixed::operator>=(const Fixed &source)
{
    if (this->fixed_point >= source.fixed_point)
	    return (true);
    return(false);
}

bool    Fixed::operator<=(const Fixed &source)
{
    if (this->fixed_point <= source.fixed_point)
	    return (true);
    return(false);
}

bool    Fixed::operator==(const Fixed &source)
{
    if (this->fixed_point == source.fixed_point)
	    return (true);
    return(false);
}

bool    Fixed::operator!=(const Fixed &source)
{
    if (this->fixed_point != source.fixed_point)
	    return (true);
    return(false);
}

float Fixed::operator+(const Fixed &source)
{
    float   temp = this->toFloat() + source.toFloat();
	return (temp);
}

float Fixed::operator-(const Fixed &source)
{
    float   temp = this->toFloat() - source.toFloat();
	return (temp);
}

float Fixed::operator/(const Fixed &source)
{
    float   temp = this->toFloat() / source.toFloat();
	return (temp);
}

float Fixed::operator*(const Fixed &source)
{
    float   temp = this->toFloat() * source.toFloat();
	return (temp);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->fixed_point++;
    return (temp);
}

Fixed Fixed::operator++()
{
    ++fixed_point;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    Fixed temp2 = temp;
    this->fixed_point--;
    return (temp2);
}

Fixed Fixed::operator--()
{
    --fixed_point;
    return (*this);
}

const Fixed	&Fixed::min(const Fixed &s1, const Fixed &s2)
{
    if (s1 > s2)
        return (s2);
    else
        return (s1);
}

const Fixed	&Fixed::max(const Fixed &s1, const Fixed &s2)
{
    if (s1 < s2)
        return (s2);
    else
        return (s1);
}

Fixed	&Fixed::min(Fixed &s1, Fixed &s2)
{
    if (s1 > s2)
        return (s2);
    else
        return (s1);
}
    
Fixed	&Fixed::max(Fixed &s1, Fixed &s2)
{
    if (s1 < s2)
        return (s2);
    else
        return (s1);
}

Fixed::~Fixed()
{

}

int		Fixed::getRawBits(void) const
{
	return (fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	fixed_point = raw;
}

