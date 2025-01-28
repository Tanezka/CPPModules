#include <iostream>
#include <vector>
#include <cctype>
#include <cstdlib>
#include "PmergeMe.hpp"
#include <cstring>
#include <ctime>

using std::cout;
using std::endl;
using std::string;

Pmergeme::Pmergeme()
{

}

Pmergeme::~Pmergeme()
{

}
    
Pmergeme::Pmergeme(Pmergeme &source)
{
    *this = source;
}

Pmergeme &Pmergeme::operator=(const Pmergeme& source)
{
	std::vector<unsigned int>	temp_vec = source.get_vec();
	std::list<unsigned int>	temp_li = source.get_li();
	std::list<unsigned int>::const_iterator ite = temp_li.begin();
	std::vector<unsigned int>::const_iterator it = temp_vec.begin();
	vec.clear();
	li.clear();
	while (it != temp_vec.end())
	{
		vec.push_back(*it);
		li.push_back(*ite);
		it++;
		ite++;
	}
	return *this;
}

const std::vector<unsigned int>	&Pmergeme::get_vec() const
{
	return (vec);
}

const std::list<unsigned int>		&Pmergeme::get_li() const
{
	return(li);
}

int Pmergeme::proccess_numbers(char **av)
{
    unsigned    int nb;
    int             i = -1;
    char            *test;

	cout << "Before: ";
    if (av[1] != NULL)
    {
        while (av[++i])
        {
            nb = static_cast<unsigned int>(std::strtoul(av[i], NULL, 10));
            vec.push_back(nb);
            li.push_back(nb);
            cout << vec.back() << " ";
        }
    }
    else
    {
        test = std::strtok(av[0], " ");
        while (test != NULL)
        {
            nb = static_cast<unsigned int>(std::strtoul(test, NULL, 10));
            vec.push_back(nb);
            li.push_back(nb);
            cout << vec.back() << " ";
            test = std::strtok(NULL, " ");
        }
    }
	cout << "\n";
    return 0;
}

std::vector<unsigned int>	Pmergeme::merge_sort(std::vector<unsigned int> a)
{
	std::vector<unsigned int> 			con1;
	std::vector<unsigned int> 			con2;
	std::vector<unsigned int>::iterator	it;
	int									i = 0;

	it = a.begin();
	if (a.size() == 1)
		return (a);
	while (it != a.end())
	{
		if (i % 2 == 0)
			con1.push_back(*it);
		else
			con2.push_back(*it);
		it++;
		i++;
	}
	
	con1 = merge_sort(con1);
	con2 = merge_sort(con2);
	return merge(con1, con2);
}

std::vector<unsigned int>	Pmergeme::merge(std::vector<unsigned int> a, std::vector<unsigned int> b)
{
	std::vector<unsigned int> c;

	while (a.size() > 0 && b.size() > 0)
	{
		if (a.front() > b.front())
		{
			c.push_back(b.front());
			//cout << "b up: " << b.front() << "\n";
			b.erase(b.begin());
		}
		else
		{
			c.push_back(a.front());
			//cout << a.front() << "\n";
			a.erase(a.begin());
		}
	}

	while (a.size() > 0)
	{
		c.push_back(a.front());
		//cout << "a: " << a.front() << "\n";
		a.erase(a.begin());
	}
	while (b.size() > 0)
	{
		c.push_back(b.front());
		//cout << "b: " << b.front() << "\n";
		b.erase(b.begin());
	}
	
	return (c);
}
	
std::list<unsigned int>	Pmergeme::merge(std::list<unsigned int> a, std::list<unsigned int> b)
{
	std::list<unsigned int> c;

	while (a.size() > 0 && b.size() > 0)
	{
		if (a.front() > b.front())
		{
			c.push_back(b.front());
			//cout << "b up: " << b.front() << "\n";
			b.pop_front();
		}
		else
		{
			c.push_back(a.front());
			//cout << a.front() << "\n";
			a.pop_front();
		}
	}

	while (a.size() > 0)
	{
		c.push_back(a.front());
		//cout << "a: " << a.front() << "\n";
		a.pop_front();
	}
	while (b.size() > 0)
	{
		c.push_back(b.front());
		//cout << "b: " << b.front() << "\n";
		b.pop_front();
	}
	
	return (c);
}

std::list<unsigned int>	Pmergeme::merge_sort(std::list<unsigned int> a)
{
	std::list<unsigned int> 			con1;
	std::list<unsigned int> 			con2;
	std::list<unsigned int>::iterator	it;
	int									i = 0;

	it = a.begin();
	if (a.size() == 1)
		return (a);
	while (it != a.end())
	{
		if (i % 2 == 0)
			con1.push_back(*it);
		else
			con2.push_back(*it);
		it++;
		i++;
	}
	
	con1 = merge_sort(con1);
	con2 = merge_sort(con2);
	return merge(con1, con2);

}

int Pmergeme::merge_insert(char **av)
{
	std::vector<unsigned int>::iterator	it;
	std::list<unsigned int>::iterator	ite;
	float								elapsed1;
	float								elapsed2;
    
	if (proccess_numbers(av) == 1)
		return 1;
	std::clock_t start = std::clock();
	vec = merge_sort(vec);
	std::clock_t end = std::clock();
	elapsed1 = (end - start);
	start = std::clock();
	li = merge_sort (li);
	end = std::clock();
	elapsed2 = (end - start);
	it = vec.begin();
	ite = li.begin();
	cout << "After: ";
	while (it != vec.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << "\n";
	cout << "Sorting time for std::vector is: " << elapsed1 << " miscrosecond.\n";
	cout << "Sorting time for std::list is: " << elapsed2 << " miscrosecond.\n";
    return 0;
}

