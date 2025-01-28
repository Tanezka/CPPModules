#include "utils.hpp"
#include <iostream>

int	main(void)
{
	Base	*dummy = NULL;
	Base	*trash = NULL;
	
	dummy = generate();
	trash = generate();
	identify(dummy);
	identify(*trash);
	if (trash != NULL)
		delete trash;
	if (dummy != NULL)
		delete dummy;
}
