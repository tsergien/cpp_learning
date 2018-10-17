#include "includes/Instruction.hpp"

Instruction::Instruction(): q(0){}
Instruction::~Instruction(){}
Instruction::Instruction(Instruction const & other){*this = other;}
Instruction & Instruction::operator=(Instruction const & other){(void)other;return *this;}

void	Instruction::push(Instruction * i)
{
	q.push_back(i);
}
Instruction *	Instruction::front()
{
	return q.front();
}
void	Instruction::pop()
{
	q.pop_front();
}

unsigned int	Instruction::size() const
{
	return q.size();
}