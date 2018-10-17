#include "DiskModule.hpp"

DiskModule::DiskModule() : IMonitorModule(){}
DiskModule::DiskModule(DiskModule const &other){*this = other;}
DiskModule::~DiskModule(){}
DiskModule	& DiskModule::operator=(DiskModule const &other)
{
	_size = other._size;
	_used = other._used;
	_available = other._available;
	_capacity = other._capacity;
	return *this;
}

void				DiskModule::set_data()
{
	char buf[100];
	FILE * filestream = popen("df -h | grep /dev/ | wc -l", "r");
	std::string s = fgets(buf, 100, filestream);
	int lines = std::strtod(s.c_str(), 0);
	_n = lines;
	std::string command = "df -h | grep /dev/ | awk '{print $1}'";

	for (int i = 0; i < 5; i++)
	{
		command[34] = i + 1 + '0';
		filestream = popen(command.c_str(), "r");
		switch(i)
		{
			case 0:
			{
				for (int j = 0; j < lines; j++)
				{
					s = fgets(buf, 100, filestream);
					s = s.substr(0, s.size() - 1);
					_name.push_back(s);
				}
				break;
			}
			case 1:
			{
				for (int j = 0; j < lines; j++)
				{
					s = fgets(buf, 100, filestream);
					s = s.substr(0, s.size() - 1);
					_size.push_back(s);
				}
				break;
			}
			case 2:
			{
				for (int j = 0; j < lines; j++)
				{
					s = fgets(buf, 100, filestream);
					s = s.substr(0, s.size() - 1);
					_used.push_back(s);
				}
				break;
			}
			case 3:
			{
				for (int j = 0; j < lines; j++)
				{
					s = fgets(buf, 100, filestream);
					s = s.substr(0, s.size() - 1);
					_available.push_back(s);
				}
				break;
			}
			case 4:
			{
				for (int j = 0; j < lines; j++)
				{
					s = fgets(buf, 100, filestream);
					s = s.substr(0, s.size() - 1);
					_capacity.push_back(s);
				}
				break;
			}
		}
		pclose(filestream);
	}
}
char const *	 	DiskModule::get_size(unsigned int i)
{
	if (i >= _size.size())
		return 0;
	return _size[i].c_str();
}
char const *	 	DiskModule::get_used(unsigned int i)
{
	if (i >= _used.size())
		return 0;
	return _used[i].c_str();
}
char const *	 	DiskModule::get_available(unsigned int i)
{
	if (i >= _available.size())
		return 0;
	return _available[i].c_str();
}
char const *	 	DiskModule::get_capacity(unsigned int i)
{
	if (i >= _capacity.size())
		return 0;
	return _capacity[i].c_str();
}
char const *	 	DiskModule::get_name(unsigned int i)
{
	if (i >= _name.size())
		return 0;
	return _name[i].c_str();
}
unsigned int	 	DiskModule::get_n() const
{
	return _n;
}