#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b1;
	Bureaucrat b2;
	Bureaucrat b3("1", 1);

	std::cout << b1;
	std::cout << b2;
	std::cout << b3;

	Bureaucrat b4("151", 151);
	Bureaucrat b5("B5", 0);
	Bureaucrat b6("B6", 55);
	std::cout << b4;
	std::cout << b5;
	std::cout << b6;

	system("leaks -q me");
	return 0;
}