#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{
	Bureaucrat s("Strong", 1);
	Bureaucrat w("Weak", 150);
	Form t28("t28", 70, 70);
	Form t1("t1", 1, 1);

	s.signForm(t28);
	w.signForm(t1);
	
	s.signForm(t28);
	w.signForm(t1);

	system("leaks -q me");
	return 0;
}