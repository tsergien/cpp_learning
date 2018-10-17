#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	std::string _target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const & target);
	~PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const & other);
	PresidentialPardonForm const & operator=(PresidentialPardonForm const & other);

	void	action() const;
};

#endif
