#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <list>
#include <stack>

template <typename T>
class MutantStack
{
public:
	MutantStack() : _st(){}
	~MutantStack(){}
	MutantStack(MutantStack const & other){
		*this = other;
	}
	operator std::stack<T>() const
	{
		std::stack<T> res;
		for (std::list<int>::const_iterator it = _st.begin(); it != _st.end(); it++)
			res.push(*it);
		return res;
	}
	MutantStack & operator=(MutantStack const & other)
	{
		_st.clear();
		for (std::list<int>::const_iterator it = other.begin(); it != other.end(); it++)
			_st.push_back(*it);
		return *this;
	}

	T const &		top() const{return _st.back();}
	bool			empty() const{return _st.empty();}
	unsigned int	size() const{return _st.size();}
	void			push(const T & elem){_st.push_back(elem);}
	void			pop(){_st.pop_back();}

	typedef typename std::list<T>::iterator iterator;
	typename std::list<T>::iterator begin(){return _st.begin();}
	typename std::list<T>::iterator end(){return _st.end();}

	typedef typename std::list<T>::const_iterator const_iterator;
	typename std::list<T>::const_iterator begin() const{return _st.begin();}
	typename std::list<T>::const_iterator end() const{return _st.end();}

private:
	std::list<T> 	_st;
};

#endif
