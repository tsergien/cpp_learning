#include "Bureaucrat.hpp"
#include "CentralBureaucracy.hpp"
#define BS 43

int main()
{
	srand(time(0));
	CentralBureaucracy cb;
	std::string pool_names[10] = {"John", "Jack", "Tom", "Petr", "Ivan", "Ted", "Bob", "Zaz", "Kat", "Ann"};
	Bureaucrat bs[BS];

	for (int i = 0; i < BS; i++)
	{
		bs[i] = Bureaucrat(pool_names[rand() % 5], rand() % 150 + 1);
		cb.feed(&bs[i]);
	}

	for (int i = 0; i < 100; i++)
	{
		std::string tar = "target";
		tar.append(std::to_string(i));
		cb.queueUp(tar);
	}

	cb.doBureaucracy();
	return 0;
}
