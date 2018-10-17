#include "CentralBureaucracy.hpp"

void	pop(t_list **head)
{
	if (!*head)
		return ;
	t_list *tmp = (*head)->next;
	delete *head;
	*head = tmp;
}

CentralBureaucracy::CentralBureaucracy(): _bur_amount(0){
	_targets = NULL;
}

CentralBureaucracy::~CentralBureaucracy(){
	while (_targets)
		pop(&_targets);
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const & other){*this = other;}
CentralBureaucracy const & CentralBureaucracy::operator=(CentralBureaucracy const & other){(void)other;return *this;}

void	CentralBureaucracy::feed(Bureaucrat *bur)
{
	try
	{
		if (_bur_amount < BLOCKS)
			_ob[_bur_amount].setIntern(new Intern);
		if (_bur_amount < BLOCKS * 2)
		{
			if (_bur_amount % 2 == 0)
			{
				_ob[_bur_amount / 2].setSigner(bur);
				_ob[_bur_amount / 2].setExecutor(bur);
			}	
			else
				_ob[_bur_amount / 2].setExecutor(bur);
			_bur_amount++;
		}
		else
			throw CentralBureaucracy::NoSeatsException();
	}
	catch (std::exception & e)
	{
		std::cout << "Cant add "<< *bur<< " cause " << e.what();;
	}
}

void	CentralBureaucracy::queueUp(std::string name)
{
	t_list *tmp = _targets;
	if (!_targets)
	{
		_targets = new t_list;
		_targets->target = name;
		_targets->next = NULL;
		return;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new t_list;
	tmp->next->target = name;
	tmp->next->next = NULL;
}

void	CentralBureaucracy::doBureaucracy()
{
	std::string names[4] = {"presidential pardon", "robotomy request", "shrubbery creation", "blah blah blah"};
	while (_targets)
	{
		std::cout << "\t*** DO BUREAUCRACY------------->";
		try
		{
			_ob[rand() % (_bur_amount / 2)].doBureaucracy(names[rand() % 4], _targets->target);
		}
		catch (Intern::NotExistingFormException & e)
		{
			std::cout << e.what();
		}
		catch (Bureaucrat::GradeTooLowException & e)
		{
			std::cout << e.what();
		}
		catch (std::exception & e)
		{
			std::cout << e.what();
		}
		pop(&_targets);
	}
}

CentralBureaucracy::NoSeatsException::NoSeatsException(){}
CentralBureaucracy::NoSeatsException::~NoSeatsException() throw(){}
CentralBureaucracy::NoSeatsException::NoSeatsException(NoSeatsException const & other){*this = other;}
CentralBureaucracy::NoSeatsException const & CentralBureaucracy::NoSeatsException::operator=(NoSeatsException const & other){
	(void)other;
	return *this;
}

const char*  CentralBureaucracy::NoSeatsException::what() const throw()
{
	return "EXC: No seats left.\n";
}