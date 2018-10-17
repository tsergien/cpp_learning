#include "CPUModule.hpp"

CPUModule::CPUModule() : IMonitorModule()
{
	char buf[400];
	FILE * filestream = popen("sysctl -n machdep.cpu.brand_string", "r");
	std::string s = fgets(buf, 400, filestream);
	_modelCPU = s.substr(0, 25);
	_clockSpeed = s.substr(32, 7);
	pclose(filestream);
	filestream = popen("sysctl -n hw.ncpu", "r");
	_cores = fgets(buf, 2, filestream);
	pclose(filestream);
}
CPUModule::CPUModule(CPUModule const &other){*this = other;}
CPUModule::~CPUModule(){}
CPUModule	& CPUModule::operator=(CPUModule const &other)
{
	_modelCPU = other._modelCPU;
	_clockSpeed = other._clockSpeed;
	_cores = other._cores;
	_userActivity = other._userActivity;
	_sysActivity = other._sysActivity;
	_idleActivity = other._idleActivity;
	return *this;
}

void				CPUModule::set_data()
{
	char buf[400];
	FILE * filestream = popen("top", "r");	
	std::string s;
	for (int i = 0; i < 4; i++)
		s = fgets(buf, 400, filestream);
	int ind = s.find("usage:") + 7;
	_userActivity = s.substr(ind, s.find("% us") + 1 - ind);
	ind = s.find("user, ") + 7;
	_sysActivity = s.substr(ind, s.find("sys,") - 1 - ind);
	ind = s.find("sys,") + 5;
	_idleActivity = s.substr(ind, s.find(" idle") - ind);
	pclose(filestream);
}


char const *	 	CPUModule::get_modelCPU() const
{
	return _modelCPU.c_str();
}
char const *	 	CPUModule::get_clockSpeed() const
{
	return _clockSpeed.c_str();
}
char const *	 	CPUModule::get_cores() const
{
	return _cores.c_str();
}
char const *	 	CPUModule::get_userActivity() const
{
	return _userActivity.c_str();
}
char const *	 	CPUModule::get_sysActivity() const
{
	return _sysActivity.c_str();
}
char const *	 	CPUModule::get_idleActivity() const
{
	return _idleActivity.c_str();
}