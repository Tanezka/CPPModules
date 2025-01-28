#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>

template <typename T>

static typename T::iterator	easyfind(T &container, int nb)
{
	typename T::iterator tmp;
	tmp = std::find(container.begin(), container.end(), nb);
	if (*tmp != nb)	
		throw (std::invalid_argument("Argument does not exist in vector."));
	return (tmp);
}

#endif
