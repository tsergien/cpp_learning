#include "includes/Array.hpp"

int main()
{
	Array<int> ar;
	Array<double> ard(5);
	
	std::cout << ard;
	for (unsigned int i = 0; i < ard.size(); i++)
		ard[i] = i + i / 10.0;

	std::cout << ard;
	ar = ard;
	std::cout << ar;
	std::cout << ar;

	try
	{
		std::cout << ar[7];
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << ar[0];
	

	return 0;
}