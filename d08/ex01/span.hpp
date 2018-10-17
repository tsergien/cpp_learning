#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <list>

class Span
{
	std::vector<int> _array;

public:
	Span();
	~Span();
	Span(unsigned int n);
	Span(Span const & other);
	Span const & operator=(Span const & other);

	int		size() const;
	void	addNumber(int num);
	int	shortestSpan() const;
	int	longestSpan() const;

	void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif
