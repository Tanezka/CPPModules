#include <iostream>
#include "Span.hpp"
#include <vector>

int main()
{
	Span sp = Span(5);
	try
	{
		//sp.fill();
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
	}
	catch(std::exception &e)
	{
		std::cout << "Vector is full!\n";
		return 0;
	}
	std::cout << "Short span: " << sp.shortestSpan() << std::endl;
	std::cout << "Long span: " << sp.longestSpan() << std::endl;
}
