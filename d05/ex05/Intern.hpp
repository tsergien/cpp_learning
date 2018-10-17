#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include <string>
#include <stdexcept>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class Intern
{
public:
	class NotExistingFormException : public std::exception
	{
		public:
		NotExistingFormException();
		~NotExistingFormException() throw() ;
		NotExistingFormException(NotExistingFormException const & other);
		NotExistingFormException const & operator=(NotExistingFormException const & other);
		virtual const char*  what() const throw();
	};
	Intern();
	~Intern();
	Intern(Intern const & other);
	Intern const & operator=(Intern const & other);

	Form*	makeForm(std::string  const & name, std::string  const & target);
};


#endif