#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", 72, 45), _target(target) {}
RobotomyRequestForm::RobotomyRequestForm(): Form("RobotomyRequestForm", 72, 45), _target("target") {}
RobotomyRequestForm::~RobotomyRequestForm(){}

void	RobotomyRequestForm::action() const
{
	srand(time(0));
	if (rand() % 2)
	{
		system("say \"drrrrrilling noise\"");
		std::cout << _target << " has been robotomized\n";
	}
	else
		system("say \"Its failure\"");
}