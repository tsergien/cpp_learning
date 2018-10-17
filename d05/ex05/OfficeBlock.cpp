#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock() : _intern(0), _signer(0), _executor(0){}
OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat * executor) :_intern(intern),\
																					 _signer(signer),\
																					_executor(executor){}
OfficeBlock::OfficeBlock(OfficeBlock const & other){*this = other;}
OfficeBlock const & OfficeBlock::operator=(OfficeBlock const & other){(void)other;return *this;}
OfficeBlock::~OfficeBlock(){}

void	OfficeBlock::setIntern(Intern * intern){_intern = intern;}
void	OfficeBlock::setSigner(Bureaucrat* signer){_signer = signer;}
void	OfficeBlock::setExecutor(Bureaucrat * executor){_executor = executor;}

void	OfficeBlock::doBureaucracy(std::string name, std::string target)
{
	Form *form = _intern->makeForm(name, target);
	_signer->signForm(*form);
	_executor->executeForm(*form);
	free(form);
}

