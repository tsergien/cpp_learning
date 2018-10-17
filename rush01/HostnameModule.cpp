//
// Created by Andrii BYTKO on 13.10.2018.
//

#include "HostnameModule.hpp"

HostnameModule::HostnameModule() : IMonitorModule() {}

HostnameModule::HostnameModule(const HostnameModule &other) {

	*this = other;
	return ;
}

HostnameModule::~HostnameModule() {}

HostnameModule& HostnameModule::operator=(HostnameModule const &other) {

	_host = other._host;
	_user = other._user;
	return *this;
}

void			HostnameModule::set_data()
{
	char buf[50];
	FILE * filestream = popen("hostname", "r");
	_host = fgets(buf, 50, filestream);
	_host = _host.substr(0, _host.size() - 1);
	pclose(filestream);
	filestream = popen("whoami", "r");
	_user = fgets(buf, 50, filestream);
	_user = _host.substr(0, _user.size() - 1);
	pclose(filestream);
}

char const *		 	HostnameModule::get_host() const
{
	return _host.c_str();
}

char const *		 	HostnameModule::get_user() const
{
	return _user.c_str();
}

std::string		HostnameModule::get_host_s() const
{
	return _host;
}

std::string		HostnameModule::get_user_s() const
{
	return _user;
}