#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :Form("ShrubberyCreationForm", 145, 137), _target(target){}
ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreationForm", 145, 137),  _target("target") {}
ShrubberyCreationForm::~ShrubberyCreationForm(){}

void	ShrubberyCreationForm::action() const
{
	std::string filename = _target;
	std::ofstream outs;

	filename.append("_shrubbery");
	outs.open(filename);
	
	outs << "                                  # #### ####\n";
	outs << "                                ### \\/#|### |/####\n";
	outs << "                               ##\\/#/ \\||/##/_/##/_#\n";
	outs << "                             ###  \\/###|/ \\/ # ###\n";
	outs << "                           ##_\\_#\\_\\## | #/###_/_####\n";
	outs << "                          ## #### # \\ #| /  #### ##/##\n";
	outs << "                           __#_--###`  |{,###---###-~\n";
	outs << "                                     \\ }{\n";
	outs << "                                      }}{\n";
	outs << "                                      }}{\n";
	outs << "                                 ejm  {{}\n";
	outs << "                                , -=-~{ .-^- _\n";
	outs << "                                      `}\n";
	outs << "                                       {\n";
}
