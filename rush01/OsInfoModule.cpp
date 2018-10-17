#include "OsInfoModule.hpp"
#include <string>

OsInfoModule::OsInfoModule() : IMonitorModule()
{
	char buf[100];
	FILE * filestream = popen("system_profiler SPSoftwareDataType", "r");
	std::string s;
	for (int i = 0; i < 5; i++)
		s = fgets(buf, 100, filestream);
	_systemV = s.substr(s.find("macOS"), 21);
	s = fgets(buf, 100, filestream);
	_kernelV = s.substr(s.find("Kernel Version:") + 16, 13);
	pclose(filestream);
}
OsInfoModule::OsInfoModule(OsInfoModule const &other){*this = other;}
OsInfoModule::~OsInfoModule(){}
OsInfoModule	& OsInfoModule::operator=(OsInfoModule const &other){
	_kernelV = other._kernelV;
	_systemV = other._systemV;
	return *this;
}

void			OsInfoModule::set_data()
{}

char const*		 	OsInfoModule::get_system_version() const
{
	return _systemV.c_str();
}

char const*		 	OsInfoModule::get_kernel_version() const
{
	return _kernelV.c_str();
}