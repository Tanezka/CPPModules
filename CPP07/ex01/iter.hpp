#ifndef ITER_HPP
# define ITER_HPP

template <typename adress, typename length, typename function>
void	iteration(adress my_adress, length my_length, function my_function)
{
	length i = -1;

	while (++i < my_length)
	{
		my_function(my_adress[i]);
	}
}

template <typename T>
void	add_one(T	&a)
{
	a += 1;
}

#endif
