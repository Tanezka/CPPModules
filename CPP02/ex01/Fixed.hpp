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
	Fixed(const Fixed &source);
	Fixed &operator=(const Fixed &source);
	~Fixed();
	Fixed(const int	num);
	Fixed(const float	num);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);
#endif
