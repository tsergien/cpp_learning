#include "mutantstack.hpp"
#include <iostream>
#include <stack>

int main()
{
	MutantStack<int> mstack;
	std::cout << "empty: " << mstack.empty() << std::endl;
	mstack.push(5);
	std::cout << "empty: " << mstack.empty() << std::endl;

	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	for (int i = 20; i < 30; i++)
		mstack.push(i);
	mstack.push(0);


	MutantStack<int> mstack2(mstack);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
