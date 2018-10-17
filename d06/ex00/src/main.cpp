#include <iostream>
#include <limits>
#include <cfloat>
#include <cstdio>
#include <iomanip>
#include <math.h>


void	to_char(long double value)
{
	if (isnan(value) || isinf(value))
		std::cout << "char: impossible\n";
	else if (value < 32.0 || value > 127.0)
		std::cout << "char: Non displayable.\n";
	else
		std::cout << "char: " <<"\'"<<  static_cast<char>(value) << "\'" << std::endl;
}

void	to_float(long double value)
{
	if (abs(value - static_cast<int>(value)) == 0)
		std::cout << std::setprecision(1) << std::fixed  << "float: " << static_cast<float>(value) << "f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout.unsetf ( std::ios::fixed );
}

void	to_double(long double value)
{
	if (abs(value - static_cast<int>(value)) == 0)
		std::cout << std::setprecision(1) << std::fixed << "double: " << value << std::endl;
	else
		std::cout << "double: " << value << std::endl;
	std::cout.unsetf ( std::ios::fixed );
}

void	to_int(long double value)
{
	if (isnan(value) || isinf(value) || value < INT_MIN || value > INT_MAX)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "usage: ./me <str1> <str2> ...\n";
	for (int i = 1; i < ac; i++)
	{
		long double value = std::strtold(av[i], NULL);
		to_char(value);
		to_int(value);
		to_float(value);
		to_double(value);
	}
	return 0;
}
