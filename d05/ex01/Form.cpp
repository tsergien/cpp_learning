#include "Form.hpp"

Form::Form(): _name("Form"), _signed(0), _sign_grade(150), _exec_grade(150){}
Form::Form(std::string name, int s_grade, int ex_grade): _name(name),\
															_signed(0),\
															_sign_grade(s_grade),\
															_exec_grade(ex_grade)
{
	try
	{
		if (s_grade < 1)
			throw Form::GradeTooHighException();
		else if (s_grade > 150)
			throw Form::GradeTooLowException();
		if (ex_grade < 1)
			throw Form::GradeTooHighException();
		else if (ex_grade > 150)
			throw Form::GradeTooLowException();
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
}
Form::~Form(){}

std::string const Form::getName() const{return _name;}
int Form::getSGrade() const{return _sign_grade;}
int Form::getEGrade() const{return _exec_grade;}
int Form::get_state() const{return _signed;}

void	Form::beSigned(Bureaucrat const & b)
{
	if (b.getGrade() <= _sign_grade)
		_signed = 1;
	else
		throw Form::GradeTooLowException();

}

std::ostream & operator<<(std::ostream & os, Form const & rhs)
{
	os << rhs.getName() << ", signed grade " << rhs.getSGrade()<<
	", execution grade " << rhs.getEGrade() << " and is ";
	if (rhs.get_state())
		std::cout << "signed.\n";
	else
		std::cout << "not signed.\n";
	return os;
}

Form::GradeTooHighException::GradeTooHighException(){}
Form::GradeTooHighException::~GradeTooHighException() throw() {}
Form::GradeTooHighException::GradeTooHighException(GradeTooHighException const & other){*this = other;}
Form::GradeTooHighException const & Form::GradeTooHighException::operator=(GradeTooHighException const & other){
	(void)other;
	return *this;
}

Form::GradeTooLowException::GradeTooLowException(){}
Form::GradeTooLowException::~GradeTooLowException() throw(){}
Form::GradeTooLowException::GradeTooLowException(GradeTooLowException const & other){*this = other;}
Form::GradeTooLowException const & Form::GradeTooLowException::operator=(GradeTooLowException const & other){
	(void)other;
	return *this;
}

const char*  Form::GradeTooHighException::what() const throw()
{
	return "EXC: Grade is too high.\n";
}

const char*  Form::GradeTooLowException::what() const throw()
{
	return "EXC: Grade is too low.\n";
}