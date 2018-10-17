#ifndef DISKMODULE_HPP
#define DISKMODULE_HPP
#include "IMonitorModule.hpp"
#include <iostream>
#include <vector>

class DiskModule : public IMonitorModule
{
	unsigned int	_n;
	std::vector<std::string> 	_name;
	std::vector<std::string>	_size;
	std::vector<std::string>	_used;
	std::vector<std::string>	_available;
	std::vector<std::string>	_capacity;

public:

	DiskModule();
	DiskModule(DiskModule const &other);
	~DiskModule();
	DiskModule	& operator=(DiskModule const &other);

	void				set_data();
	char const *		get_size(unsigned int i);
	char const *		get_used(unsigned int i);
	char const *		get_available(unsigned int i);
	char const *		get_capacity(unsigned int i);
	char const *		get_name(unsigned int i);
	unsigned int		get_n() const;
};


#endif