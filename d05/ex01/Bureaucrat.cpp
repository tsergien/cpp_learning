#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Scrooge. Scrooge McDuck"), _grade(1) {}
Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			_grade = grade;
	}
	catch (std::exception& e)
	{
		_grade = 7;
		std::cout << e.what();
	}
}

Bureaucrat::~Bureaucrat(){}
Bureaucrat::Bureaucrat(Bureaucrat const & other){
	*this = other;
}
Bureaucrat const & Bureaucrat::operator=(Bureaucrat const & other){
	_grade = other.getGrade();
	return *this;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(){}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}
Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const & other){*this = other;}
Bureaucrat::GradeTooHighException const & Bureaucrat::GradeTooHighException::operator=(GradeTooHighException const & other){
	(void)other;
	return *this;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(){}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw(){}
Bureaucrat::GradeTooLowException::GradeTooLowException(GradeTooLowException const & other){*this = other;}
Bureaucrat::GradeTooLowException const & Bureaucrat::GradeTooLowException::operator=(GradeTooLowException const & other){
	(void)other;
	return *this;
}

const char*  Bureaucrat::GradeTooHighException::what() const throw()
{
	return "EXC: Grade is too high.\n";
}

const char*  Bureaucrat::GradeTooLowException::what() const throw()
{
	return "EXC: Grade is too low.\n";
}


std::string const & Bureaucrat::getName() const{return _name;}
int			Bureaucrat::getGrade() const{return _grade;}

// Remember, grade 1 is highest,
// 150 is lowest, so incrementing a grade 3 gives you a grade 2 ...
void				Bureaucrat::increment()
{
	try
	{
		if (_grade < 2)
			throw Bureaucrat::GradeTooHighException();
		else
			_grade--;
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
}

void				Bureaucrat::decrement()
{
	try
	{
		if (_grade > 149)
			throw Bureaucrat::GradeTooLowException();
		else
			_grade++;
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}
}

void		Bureaucrat::signForm(Form & f)
{
	try
	{
		f.beSigned(*this);
		if (f.get_state() == 0)
			throw Bureaucrat::GradeTooLowException();
		else
			std::cout << *this << " signs " << f;
	}
	catch (std::exception& e)
	{
		std::cout << *this << " cannot sign " << f << " because: ";
		std::cout << e.what();
	}
}

std::ostream & operator<<(std::ostream & os, Bureaucrat const & rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return os;
}
