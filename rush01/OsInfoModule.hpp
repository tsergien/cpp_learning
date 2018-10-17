#ifndef OSINFOMODULE_HPP
#define OSINFOMODULE_HPP
#include <iostream>
#include "IMonitorModule.hpp"

class OsInfoModule : public IMonitorModule
{
	std::string		_systemV;
	std::string		_kernelV;
public:

	OsInfoModule();
	OsInfoModule(OsInfoModule const &other);
	~OsInfoModule();
	OsInfoModule	&operator=(OsInfoModule const &other);

	void				set_data();
	char const *	 	get_system_version() const;
	char const *	 	get_kernel_version() const;
};


#endif 
