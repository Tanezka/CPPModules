#ifndef FIXED_H
# define FIXED_H
# include <iostream>

class Fixed
{
private:
	int					fixed_point;
	static const int	bits = 8;

public:
	Fixed();
	Fixed(const int	num);
	Fixed(const float	num);
	Fixed(const Fixed &source);
	Fixed    &operator=(const Fixed &source);
	bool    operator<(const Fixed &source) const;
	bool    operator<=(const Fixed &source);
    bool    operator>(const Fixed &source) const;
	bool    operator>=(const Fixed &source);
	bool    operator==(const Fixed &source);
	bool    operator!=(const Fixed &source);
	float     operator+(const Fixed &source);
	float     operator-(const Fixed &source);
	float     operator/(const Fixed &source);
	float     operator*(const Fixed &source);
	Fixed   operator++();
	Fixed   operator++(int);
	Fixed   operator--();
	Fixed   operator--(int);
    ~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
    static const Fixed     &min(const Fixed &s1, const Fixed &s2); 
    static const Fixed     &max(const Fixed &s1, const Fixed &s2);
    static Fixed     &min(Fixed &s1, Fixed &s2); 
    static Fixed     &max(Fixed &s1, Fixed &s2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);
#endif
