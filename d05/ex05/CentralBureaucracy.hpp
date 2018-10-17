#ifndef CENTRALBUREAUCRACY_HPP
#define CENTRALBUREAUCRACY_HPP
#include <iostream>
#include <string>
#include <stdexcept>
#include "OfficeBlock.hpp"
#define BLOCKS 20
#define INIT_TARG 50

typedef struct 	s_list
{
	std::string target;
	struct s_list *next;
}				t_list;

class CentralBureaucracy
{
	int				_bur_amount;
	OfficeBlock		_ob[BLOCKS];
	t_list 			*_targets;
public:
	class NoSeatsException : public std::exception
	{
		public:
		NoSeatsException();
		~NoSeatsException() throw() ;
		NoSeatsException(NoSeatsException const & other);
		NoSeatsException const & operator=(NoSeatsException const & other);
		virtual const char*  what() const throw();
	};
	CentralBureaucracy();
	~CentralBureaucracy();
	CentralBureaucracy(CentralBureaucracy const & other);
	CentralBureaucracy const & operator=(CentralBureaucracy const & other);

	void	feed(Bureaucrat *bur);
	void	queueUp(std::string name);
	void	doBureaucracy();
};

#endif
