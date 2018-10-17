#ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP
#include <iostream>
#include <string>
#include <stdexcept>
#include "Intern.hpp"


class OfficeBlock
{
	Intern		*_intern;
	Bureaucrat *_signer;
	Bureaucrat *_executor;

	OfficeBlock(OfficeBlock const & other);
	OfficeBlock const & operator=(OfficeBlock const & other);
public:
	
	OfficeBlock();
	OfficeBlock(Intern *intern, Bureaucrat *signer, Bureaucrat * executor);
	~OfficeBlock();

	void	setIntern(Intern * intern);
	void	setSigner(Bureaucrat * signer);
	void	setExecutor(Bureaucrat * executor);
	void	doBureaucracy(std::string const & name, std::string const & target);
};

#endif