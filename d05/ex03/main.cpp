#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{

	Intern someRandomIntern;
	Form* rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");


	Intern a;
	Form *form;

	form = a.makeForm("blbla", "target");
	form = a.makeForm("presidential pardon", "target");
	form = a.makeForm("shrubbery creation", "target");
	form = a.makeForm("unnamed form", "target");

	system("leaks -q me");

	return 0;
}