#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include "includes/Instruction.hpp"
#include "includes/Rshift.hpp"
#include "includes/Lshift.hpp"
#include "includes/Incr.hpp"
#include "includes/Decr.hpp"
#include "includes/Dot.hpp"
#include "includes/Coma.hpp"
#include "includes/OpenBracket.hpp"
#include "includes/CloseBracket.hpp"

static char cpu[30000];

Instruction * generate(char c)
{
	switch(c)
	{
		case '>': return (new Rshift);
		case '<': return (new Lshift);
		case '+': return (new Incr);
		case '-': return (new Decr);
		case '.': return (new Dot);
		case ',': return (new Coma);
		case '[': return (new OpenBracket);
		case ']': return (new CloseBracket);
	}
	return 0;
}

void	execute(std::vector<char> & q)
{
	int brackets = 0;
	unsigned int count = 0;
	for (unsigned int i = 0; i < q.size(); i++)
	{
		if (q[i] == '>')
			count++;
		else if (q[i] == '<')
			count--;
		else if (q[i] == '+')
			cpu[count]++;
		else if (q[i] == '-')
			cpu[count]--;
		else if (q[i] == '.')
			std::cout << cpu[count];
		else if (q[i] == ',')
			std::cin >> cpu[count];
		else if (q[i] == '[')
		{
			if (!cpu[count])
			{
					++brackets;
				while (brackets)
				{
					i++;
					if (q[i] == '[')
						++brackets;
					else if (q[i] == ']')
						--brackets;
				}
			}
			else continue ;
		}
		else if (q[i] == ']')
		{
			if (!cpu[count]) continue;
			else
			{
				if (q[i] == ']')
					brackets++;
				while (brackets)
				{
					--i;
					if (q[i] == '[')
						brackets--;
					else if (q[i] == ']')
						brackets++;
				}
				--i;
			}
		}
	}
}

int main(int ac, char **av)
{
	for (int i = 0; i < ac; i++)
	{
		std::ifstream ins;
		if (i == 0)
		{
			ins.open("midopen_code");
			i++;
		}
		else
			ins.open(av[i]);
		std::string s;
		std::stringstream ss;
		ss << ins.rdbuf();
		s = ss.str();
		ss.clear();
		ins.close();

		// std::deque<Instruction*> q;
		Instruction q;
		for (unsigned j = 0; j < s.size(); j++)
			q.push(generate(s[i]));
		int brackets = 0;
		unsigned int count = 0;
		for (int j = 0; j < q.size(); j++)
		{
			q.front()->execute(&count, cpu);
			
		}

	}
	return 0;
}