#include <iostream>
#include <stack>
#include "MutantStack.hpp"

int main(void)
{
	MutantStack<int> mstack;
	const MutantStack<int> test;
	MutantStack<int>::const_reverse_iterator kat;
	kat = test.rbegin();
	mstack.push(5);
	mstack.push(17);
	//std::cout << mstack.top() << std::endl;
	//mstack.pop();
	//std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	//mstack.pop();
	MutantStack<int>::iterator it = mstack.begin();
	std::cout << "begin: " << *it << std::endl;
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	//mstack.pop();
	std::cout << "toppppppp: "<< mstack.top() << std::endl;
	std::cout << "toppppppp: "<< s.top() << std::endl;

	const MutantStack<int> constack(mstack);
	MutantStack<int>::const_iterator iter = constack.begin();
	std::cout << "test iter: " << *iter << "\n";

	return 0;
}
