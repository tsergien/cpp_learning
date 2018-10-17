#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP
#include <deque>

class Instruction
{
protected:
	std::deque<Instruction*> q;
public:
	Instruction();
	~Instruction();
	Instruction(Instruction const & other);
	Instruction & operator=(Instruction const & other);

	void	push(Instruction * i);
	Instruction *	front();
	void	pop();
	unsigned int	size() const;
	virtual void	execute(unsigned int *count, char (&cpu)[30000]) = 0;
};

#endif