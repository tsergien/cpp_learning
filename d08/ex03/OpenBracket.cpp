#include "includes/OpenBracket.hpp"
#include "includes/CloseBracket.hpp"

OpenBracket::OpenBracket(){}
OpenBracket::~OpenBracket(){}
OpenBracket::OpenBracket(OpenBracket const & other){*this = other;}
OpenBracket & OpenBracket::operator=(OpenBracket const & other){
	(void)other;
	return *this;
}
 
void	OpenBracket::execute(unsigned int *count, char (&cpu)[30000])
{
	int brc = 0;
	if (!cpu[*count])
	{
		++brc;
		while (brc)
		{
			(*count)++;
			if (dynamic_cast<OpenBracket*>(q.front()))
				++brc;
			if (dynamic_cast<CloseBracket*>(q.front()))
				--brc;
		}
	}

}
