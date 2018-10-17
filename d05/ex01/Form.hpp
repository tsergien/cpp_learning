#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	std::string const _name;
	bool		_signed;
	int	const	_sign_grade;
	int	const	_exec_grade;

	Form(Form const & other);
	Form const & operator=(Form const & other);
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

	Form();
	Form(std::string name, int s_grade, int ex_grade);
	~Form();

	std::string const getName() const;
	int getSGrade() const;
	int getEGrade() const;
	int get_state() const;

	void	beSigned(Bureaucrat const & b);

};

std::ostream & operator<<(std::ostream & os, Form const & rhs);

#endif
