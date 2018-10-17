#include "span.hpp"


int main()
{
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::vector<int> v(10000, 3);
	v.insert(v.begin() + 100, 7);
	v.insert(v.begin() + 500, 73);

	Span span(10002);
	span.addNumber(v.begin(), v.end());

	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;

	return 0;

}