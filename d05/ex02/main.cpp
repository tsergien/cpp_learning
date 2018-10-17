#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{

	Bureaucrat	b("Petr", 77);
	Bureaucrat	t("Ivan", 1);

	PresidentialPardonForm pres(b.getName());
	RobotomyRequestForm rob(b.getName());
	ShrubberyCreationForm sh(t.getName());

	t.executeForm(pres);
	std::cout <<"\n\n";

	b.signForm(pres);
	t.signForm(pres);
	t.signForm(rob);
	t.signForm(sh);
	std::cout <<"\n\n";

	b.executeForm(pres);
	t.executeForm(pres);
	t.executeForm(rob);
	t.executeForm(sh);


	system("leaks -q me");

	return 0;
}