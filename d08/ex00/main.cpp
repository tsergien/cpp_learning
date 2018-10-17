#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <stack>
#include <iterator>

template <typename Container>
int	easyfind(Container const & con, int i)
{
	typename Container::const_iterator it;
	it = find(con.begin(), con.end(), i);
	if (it == con.end())
		throw std::out_of_range("No such element if the container.");
	return std::distance(con.begin(), it);
}

int main()
{
	int a[6] = {0, 1, 2, 3, 4, 5};
	std::vector<int> v(a, a + sizeof(a) / sizeof(int));
	std::list<int> l(a, a + sizeof(a) / sizeof(int));
	std::deque<int> dq(6, 1);

/*
//-----------VECTOR
	std::vector<int>::iterator it;
	it =  std::find(v.begin(), v.end(), 1);
	std::cout << "it : " << *it << std::endl;
	it =  std::find(v.begin(), v.end(), 6);
	std::cout << "it not found : " << *it << std::endl;
	std::cout << "--last : " << *(--v.end()) << std::endl;
	std::cout << "last : " << *v.end() << std::endl;
//-------------DEQUE
	std::deque<int>::iterator itq;
	itq =  std::find(dq.begin(), dq.end(), 6);
	std::cout << "it : " << *itq << std::endl;
	itq =  std::find(dq.begin(), dq.end(), 6);
	std::cout << "it not found : " << *itq << std::endl;
	std::cout << "--last : " << *(--dq.end()) << std::endl;
	std::cout << "last : " << *dq.end() << std::endl;

//-------------LIST
	{std::list<int>::iterator itl;
	itl =  std::find(l.begin(), l.end(), 1);
	std::cout << "itl : " << *itl << std::endl;
	itl =  std::find(l.begin(), l.end(), 6);
	std::cout << "itl not found: " << *itl << std::endl;
	std::cout << "itl last: " << *(--l.end()) << std::endl;
	std::cout << "itl --last: " << *l.end() << std::endl;
	}*/


	try
	{
	std::cout << "easyfind(l, 1): " << easyfind(l, 1)<< std::endl;
	std::cout << "easyfind(v, 1): " << easyfind(v, 1)<< std::endl;
	std::cout << "easyfind(dq, 1): " << easyfind(dq, 1)<< std::endl;
	std::cout << "easyfind(v, 6): " << easyfind(v, 6)<< std::endl;
	std::cout << "easyfind(l, 6): " << easyfind(l, 6)<< std::endl;
	std::cout << "easyfind(dq, 6): " << easyfind(dq, 6)<< std::endl;
	}
	catch (std::out_of_range & e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}