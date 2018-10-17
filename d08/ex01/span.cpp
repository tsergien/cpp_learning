#include "span.hpp"

Span::Span() :  _array(0){}
Span::~Span(){}
Span::Span(unsigned int n){
	_array.reserve(n);
}
Span::Span(Span const & other){*this= other;}
Span const & Span::operator=(Span const & other){
	_array = other._array;
	return *this;
}

void	Span::addNumber(int num){
	if (_array.size() >= _array.capacity())
		throw std::out_of_range("Array is already filled!");
	_array.push_back(num);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_array.size() >= _array.capacity())
		throw std::out_of_range("Array is already filled!");
	std::vector<int>::iterator it;
	for (it = begin; it != end; it++)
		_array.push_back(*it);
}

int		Span::shortestSpan() const{
	if (_array.empty() || _array.size() < 2)
		throw std::range_error("Not enough elements.");
	int span = abs(_array[0] - _array[1]);
	std::vector<int>::const_iterator it;
	std::vector<int>::const_iterator another_it;
	
	for (it = _array.begin() + 1; it < _array.end(); it++)
	{
		for (another_it = it + 1; another_it < _array.end(); another_it++)
		{
			if (abs(*it - *another_it) < span)
			{
				span = abs(*it - *another_it);
				if (span == 0)
					return span;
			}

		}
	}
	return span;
}

int		Span::longestSpan() const{
	if (_array.empty() || _array.size() == 1)
		throw std::range_error("Not enough elements.");
	std::vector<int>::const_iterator max_it = std::max_element(_array.begin(), _array.end());
	std::vector<int>::const_iterator min_it = std::min_element(_array.begin(), _array.end());
	return *max_it - *min_it;
}
