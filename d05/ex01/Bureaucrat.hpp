#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <stdexcept>

class Form;

class Bureaucrat
{
	std::string const _name;
	unsigned	_grade;
public:
	class GradeTooHighException : public std::exception
	{
		public:
		GradeTooHighException();
		~GradeTooHighException() throw() ;
		GradeTooHighException(GradeTooHighException const & other);
		GradeTooHighException const & operator=(GradeTooHighException const & other);
		virtual const char*  what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		public:
		GradeTooLowException();
		~GradeTooLowException() throw() ;
		GradeTooLowException(GradeTooLowException const & other);
		GradeTooLowException const & operator=(GradeTooLowException const & other);
		virtual const char*  what() const throw();
	};

	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(Bureaucrat const & other);
	Bureaucrat const & operator=(Bureaucrat const & other);

	std::string const & getName() const;
	int					getGrade() const;
	void				increment();
	void				decrement();

	void			signForm(Form & f);
};

std::ostream & operator<<(std::ostream & os, Bureaucrat const & rhs);

#endif
