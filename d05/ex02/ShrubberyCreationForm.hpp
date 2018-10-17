#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	std::string _target;
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm();
	~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const & other);
	ShrubberyCreationForm const & operator=(ShrubberyCreationForm const & other);

	void	action() const;
};

#endif
