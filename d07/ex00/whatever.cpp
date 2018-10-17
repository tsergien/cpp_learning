#include <iostream>

template <class T>
void	swap(T & a, T & b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <class T>
T	min(T const & a, T const & b)
{
	return (a < b) ? a : b;
}

template <class T>
T	max(T const & a, T const & b)
{
	return (a > b) ? a : b;
}

int main()
{
	int a = 5;
	int b = 7;
std::cout << "*** INT ***\n";
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
	swap(a, b);
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

std::cout << "*** DOUBLE ***\n";
	double da = 5, db = 7;
	std::cout << "a = " << da << std::endl;
	std::cout << "b = " << db << std::endl;
	std::cout << "min(a, b) = " << ::min(da, db) << std::endl;
	std::cout << "max(a, b) = " << ::max(da, db) << std::endl;
	swap(da, db);
	std::cout << "a = " << da << std::endl;
	std::cout << "b = " << db << std::endl;

	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{
		int *a1 = new int, *a2= new int;
		*a1 = 77;
		*a2 = 78;
		std::cout << "*a1 = " << *a1 << std::endl;
		std::cout << "*a2 = " << *a2 << std::endl;
		swap(a1, a2);
		std::cout << "*a1 = " << *a1 << std::endl;
		std::cout << "*a2 = " << *a2 << std::endl;
		swap(*a1, *a2);
		std::cout << "*a1 = " << *a1 << std::endl;
		std::cout << "*a2 = " << *a2 << std::endl;
	}	


	return 0;
}

