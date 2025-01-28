#ifndef DATA_HPP
# define DATA_HPP

struct Data
{
	int	value;

	Data();
	~Data();
	Data(const Data &other);
	Data &operator=(const Data &other);
};
#endif
