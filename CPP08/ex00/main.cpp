#include <iostream>
#include "easyfind.hpp"
#include <vector>

int main( void ) 
{
	typedef std::vector<int>	container;
	container					vec;
	const	int					to_find = 4;

    srand(time(NULL));
	std::cout << "vector: {";
	while (vec.size() <= 10)
	{
		vec.push_back(rand() % 10);
		std::cout << vec.back();
		if (vec.size() <= 10)
			std::cout << ", ";
	}
	std::cout << "}.\n";
	try
	{
		container::iterator it = easyfind<container>(vec, to_find);
		std::cout << "Number " << *it << " is found!\n";
		std::cout << "Changing occurrence to 42!\n";
		*it = 42;
		container::iterator index;
		std::cout << "vector: {";
		index = vec.begin();
		while (index != (vec.end()))
		{
			std::cout << *index;
			index++;
			if (index != (vec.end()))
				std::cout << ", ";
		}
		std::cout << "}.\n";
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	
	return 0;
}
