#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	std::string _target;
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const & other);
	RobotomyRequestForm const & operator=(RobotomyRequestForm const & other);

	void	action() const;
};

#endif
