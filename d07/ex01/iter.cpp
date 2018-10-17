#include <iostream>

template<typename T>
void 	print(T & elem)
{
	std::cout << elem << std::endl;
}

template<typename T>
void	fill(T & elem)
{
	elem = static_cast<T>(7.5);
}

// template <typename T, typename SIZET, typename Func>
// void		iter(T *ar, SIZET len, Func (*f)(T & elem))
// {
// 	if (len == 0 || !f || !ar)	
// 		return;
// 	for (int i = 0; i < len; i++)
// 	{
// 		f(ar[i]);
// 	}
// }

template <typename T, typename SIZET>
void		iter(T *ar, SIZET len, void (*f)(T & elem))
{
	for (int i = 0; i < len; i++)
	{
		f(ar[i]);
	}
}

int main()
{
	int * array = new int[5];
	iter(array, 5, fill);
	iter(array, 5, print);

	double * darray = new double[10];
	iter(darray, 10, fill);
	iter(darray, 10, print);

	return 0;
}