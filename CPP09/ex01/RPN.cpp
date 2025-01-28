#include <iostream>
#include "RPN.hpp"

using std::cout;
using std::endl;
using std::string;

Rpn::Rpn()
{

}

Rpn::~Rpn()
{

}
    
Rpn::Rpn(Rpn &source)
{
    *this = source;
}

const stack<int>	&Rpn::get_stack() const
{
	return(mstack);	
}

Rpn &Rpn::operator=(const Rpn& source)
{
	std::stack<int>	rstack = source.get_stack();
	std::stack<int>	copy;
	std::stack<int>	temp;
	while (!rstack.empty())
	{
		temp.push(rstack.top());
		rstack.pop();
	}
	
	while (!temp.empty())
	{
		rstack.push(temp.top());
		copy.push(temp.top());
		temp.pop();
	}
	mstack = copy;
	return *this;
}

int Rpn::operations(char *av)
{
    int i = -1;
	bool	ope = false;

	if (av[0] == 0)
		return 1;
    while (av[++i])
    {
        if (isspace(av[i]) != 0)
            continue;
		else if (i != 0 && isspace(av[i - 1]) == 0)
			return 1;
        if (isdigit(av[i]) != 0)
            mstack.push(av[i] - '0');
        else if (av[i] == '*' && mstack.size() >= 2)
        {
            int a = mstack.top();
            mstack.pop();
            int b = mstack.top();
            mstack.pop();
            mstack.push(b * a);
			ope = true;
        }
        
        else if (av[i] == '+' && mstack.size() >= 2)
        {
            int a = mstack.top();
            mstack.pop();
            int b = mstack.top();
            mstack.pop();
            mstack.push(b + a);
			ope = true;
        }
        
        else if (av[i] == '/' && mstack.size() >= 2)
        {
            int a = mstack.top();
            mstack.pop();
            int b = mstack.top();
            mstack.pop();
            mstack.push(b / a);
			ope = true;
        }
        else if (av[i] == '-' && mstack.size() >= 2)
        {
            int a = mstack.top();
            mstack.pop();
            int b = mstack.top();
            mstack.pop();
            mstack.push(b - a);
			ope = true;
        }
        else
            return 1;
    }
	if (ope && mstack.size() == 1)
	{
    	std::cout << "Answer: " << mstack.top() << "\n";
		return 0;
	}
    return (1);
}
