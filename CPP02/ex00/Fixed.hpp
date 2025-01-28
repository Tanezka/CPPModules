#ifndef FIXED_H
# define FIXED_H

class Fixed
{
private:
	int					fixed_point;
	static const int	bits = 8;

public:
	Fixed();
	Fixed(Fixed &source);
	Fixed &operator=(const Fixed &source);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};
#endif
