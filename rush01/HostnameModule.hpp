//
// Created by Andrii BYTKO on 13.10.2018.
//

#ifndef HOSTNAMEMODULE_HPP
#define HOSTNAMEMODULE_HPP

#include <cstdlib>
#include "IMonitorModule.hpp"

class HostnameModule : public IMonitorModule
{

private:

	std::string _user;
	std::string _host;
public:

	HostnameModule();
	HostnameModule(HostnameModule const &other);
	~HostnameModule();
	HostnameModule	&operator=(HostnameModule const &other);

	void			set_data();
	char const *	get_host() const;
	char const *	get_user() const;
	std::string		get_host_s() const;
	std::string		get_user_s() const;
};


#endif
