#include "Base.hpp"
#include "B.hpp"
#include "A.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base	*create_a(void)
{
	return new A();	
}
Base	*create_b(void)
{
	return new B();	
}
Base	*create_c(void)
{
	return new C();	
}

void identify(Base* p)
{
	if (p == NULL)
	{
		std::cout << "Unknown type.\n";
		return;
	}
	if (dynamic_cast<A*>(p))
		std::cout << "Type is A.\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "Type is B.\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "Type is C.\n";
	else
		std::cout << "Unknown type.\n";
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type is A.\n";
		return;
	}

	catch (std::bad_cast &e)
	{

	}
	
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Type is B.\n";
		return;
	}
	
	catch (std::bad_cast &e)
	{

	}
	
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Type is C.\n";
		return;
	}
	
	catch (std::bad_cast &e)
	{

	}

	std::cout << "Unknown type.\n";

}

Base *generate(void)
{
    int random;

	Base *(*fpointer[3])(void) = {create_a, create_b, create_c};
    srand(time(NULL));
    random = rand() % 3;
	std::cout << "Generating...\n";
	return (fpointer[random]());
}
