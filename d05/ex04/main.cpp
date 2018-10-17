#include "Bureaucrat.hpp"
#include "OfficeBlock.hpp"


/*     *** NO EXOSTING FORM  ***        
int main()
{
	srand(time(0));
	Intern *idiotOne = new Intern;;
	Bureaucrat  *hermes = new Bureaucrat("Hermes Conrad", 37);
	Bureaucrat *bob = new Bureaucrat("Bobby Bobson", 123);
	OfficeBlock ob;
	ob.setIntern(idiotOne);
	ob.setSigner(bob);
	ob.setExecutor(hermes);
	try
	{
		ob.doBureaucracy("mutant pig", "Pigley");
	}
	catch (Intern::NotExistingFormException & e)
	{
		std::cout << e.what();
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what();
	}

	return 0;
}*/


/*     *** TOO LOW GRADE  ***        */
int main()
{

	Intern *idiotOne = new Intern;;
	Bureaucrat  *hermes = new Bureaucrat("Hermes Conrad", 37);
	Bureaucrat *bob = new Bureaucrat("Bobby Bobson", 123);
	OfficeBlock ob;

	ob.setIntern(idiotOne);
	ob.setSigner(bob);
	ob.setExecutor(hermes);
	try
	{
		ob.doBureaucracy("presidential pardon", "Pigley");
	}
	catch (Intern::NotExistingFormException & e)
	{
		std::cout << e.what();
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << e.what();
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}

	return 0;
}


