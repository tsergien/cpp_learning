#include "RAMModule.hpp"

RAMModule::RAMModule()
{
	char buf[50];
	FILE * filestream = popen("system_profiler SPMemoryDataType", "r");
	std::string s;
	for (int i = 0; i < 10; i++)
		s = fgets(buf, 50, filestream);
	int ind = s.find(":") + 2;
	_size = s.substr(ind, s.find("\n") - ind);
	
	s = fgets(buf, 50, filestream);
	ind = s.find(":") + 2;
	_type = s.substr(ind, s.find("\n") - 1 - ind);
	s = fgets(buf, 50, filestream);
	ind = s.find(":") + 2;
	_speed = s.substr(ind, s.find("\n") - 1 - ind);
	pclose(filestream);
}
RAMModule::RAMModule(RAMModule const &other){*this = other;}
RAMModule::~RAMModule(){}
RAMModule	& RAMModule::operator=(RAMModule const &other)
{
	_size = other._size;
	_type = other._type;
	_speed = other._speed;
	_used = other._used;
	_unused = other._unused;
	_wired = other._wired;
	return *this;
}

void				RAMModule::set_data()
{
	char buf[50];
	std::string s;
	FILE *filestream = popen("top -l 1 | grep PhysMem", "r");
	s = fgets(buf, 50, filestream);
	int ind = s.find(":") + 2;
	_used = s.substr(ind, s.find("M us") - ind + 1);
	ind = s.find("(") + 1;
	_wired = s.substr(ind, s.find("M w") - ind + 1);
	ind = s.find("),") + 3;
	_unused = s.substr(ind, s.find("M un") - ind + 1);
	pclose(filestream);
}

char const *	 	RAMModule::get_size() const
{
	return _size.c_str();
}
char const *	 	RAMModule::get_type() const
{
	return _type.c_str();
}
char const *	 	RAMModule::get_speed() const
{
	return _speed.c_str();
}
char const *	 	RAMModule::get_used() const
{
	return _used.c_str();
}
char const *	 	RAMModule::get_wired() const
{
	return _wired.c_str();
}
char const *	 	RAMModule::get_unused() const
{
	return _unused.c_str();
}