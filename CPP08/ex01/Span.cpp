#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

Span::Span()
{
	std::cout << "Constructer with no parameter has been activated.\nYou must declare a Span Object with an int parameter.\n";
}

Span::~Span()
{

}

Span::Span(const Span &tmp)
{
	*this = tmp;
}
        
Span &Span::operator=(const Span &source)
{
	std::vector<int>::const_iterator it = source.begin();
	vector.clear();
	while (it != source.end())
	{
		vector.push_back(*it);
		it++;
	}
	max_size = source.size();
	return (*this);
}

Span::Span(unsigned int nb): max_size(nb)
{

}

int	Span::shortestSpan()
{
	int							nb1;
	int							nb2;
	int							abs_min = std::numeric_limits<int>::max();
	int							min;
	std::vector<int>::iterator	it1;
	std::vector<int>::iterator	it2;

	std::sort(vector.begin(), vector.end());
	it1 = vector.begin();
	it2 = it1;
	it2++;
	while (it2 != vector.end())
	{
		min = std::abs(*it1 - *it2);
		if (min < abs_min)
		{
			nb1 = std::max(*it1, *it2);
			nb2 = std::min(*it1, *it2);
			abs_min = min;
		}
		it1++;
		it2++;
	}
	std::cout << nb1 << " - ";
	std::cout << nb2 << " = ";
	return (abs_min);
}
		
int	Span::longestSpan()
{
	std::cout << *std::max_element(vector.begin(), vector.end()) << " - ";
	std::cout << *std::min_element(vector.begin(), vector.end()) << " = ";
	return (*std::max_element(vector.begin(), vector.end()) - *std::min_element(vector.begin(), vector.end()));
}

void	Span::addNumber(int nb)
{
	if (vector.size() < max_size)
		vector.push_back(nb);
	else
		throw std::exception();
}

std::vector<int>::iterator	Span::begin()
{
	return (vector.begin());
}

std::vector<int>::const_iterator	Span::begin() const
{
	return (vector.begin());
}

std::vector<int>::iterator	Span::end()
{
	return (vector.end());
}

std::vector<int>::const_iterator	Span::end() const
{
	return (vector.end());
}

unsigned	int	Span::size() const
{
	return (vector.size());
}

void	Span::fill()
{
    srand(time(NULL));
	while (vector.size() < max_size)
		vector.push_back(rand());
}
