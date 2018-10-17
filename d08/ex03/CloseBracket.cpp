#include "includes/CloseBracket.hpp"
#include "includes/OpenBracket.hpp"

CloseBracket::CloseBracket(){}
CloseBracket::~CloseBracket(){}
CloseBracket::CloseBracket(CloseBracket const & other){*this = other;}
CloseBracket & CloseBracket::operator=(CloseBracket const & other){
	(void)other;
	return *this;
}

void	CloseBracket::execute(unsigned int *count, char (&cpu)[30000])
{
	int brc = 0;
	int i = 0;
	if (cpu[*count])
	{
		if (dynamic_cast<CloseBracket*>(q[i]))
			brc++;
		while (brc)
		{
			--i;
			if ()
		}
		--i;
	}
}