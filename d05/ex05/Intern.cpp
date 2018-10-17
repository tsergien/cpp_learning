#include "Intern.hpp"

Intern::Intern(){}
Intern::~Intern(){}
Intern::Intern(Intern const & other){*this = other;}
Intern const & Intern::operator=(Intern const & other){(void)other;return *this;}


Form*	Intern::makeForm(std::string const & name, std::string const & target)
{
	Form * f = NULL;
	if (name == (std::string)"robotomy request")
	{
		f = new RobotomyRequestForm(target);
		std::cout << "Intern creates " << *f << " targeted on "<< target << std::endl;
	}	
	else if (name == (std::string)"presidential pardon")
	{
		f = new PresidentialPardonForm(target);
		std::cout << "Intern creates " << *f << " targeted on "<< target << std::endl;
	}
	else if (name == (std::string)"shrubbery creation")
	{
		f = new ShrubberyCreationForm(target);
		std::cout << "Intern creates " << *f << " targeted on "<< target << std::endl;
	}
	else
		throw Intern::NotExistingFormException();
	return f;
}

Intern::NotExistingFormException::NotExistingFormException(){}
Intern::NotExistingFormException::~NotExistingFormException() throw(){}
Intern::NotExistingFormException::NotExistingFormException(NotExistingFormException const & other){*this = other;}
Intern::NotExistingFormException const & Intern::NotExistingFormException::operator=(NotExistingFormException const & other){
	(void)other;
	return *this;
}

const char*  Intern::NotExistingFormException::what() const throw()
{
	return "EXC: Not existing form.\n";
}