#ifndef CPUMODULE_HPP
#define CPUMODULE_HPP
#include "IMonitorModule.hpp"
#include <iostream>

class CPUModule : public IMonitorModule
{
	std::string		_modelCPU;
	std::string		_clockSpeed;
	std::string		_cores;
	std::string		_userActivity;
	std::string		_sysActivity;
	std::string		_idleActivity;
public:

	CPUModule();
	CPUModule(CPUModule const &other);
	~CPUModule();

	CPUModule	&operator=(CPUModule const &other);

	void				set_data();
	char const *	 	get_modelCPU() const;
	char const *	 	get_clockSpeed() const;
	char const *	 	get_cores() const;
	char const *	 	get_userActivity() const;
	char const *	 	get_sysActivity() const;
	char const *	 	get_idleActivity() const;
};


#endif
