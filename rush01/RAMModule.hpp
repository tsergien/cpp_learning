#ifndef RAMMODULE_HPP
#define RAMMODULE_HPP
#include "IMonitorModule.hpp"
#include <iostream>

class RAMModule : public IMonitorModule
{
	std::string	_size;
	std::string	_type;
	std::string	_speed;
	std::string	_used;
	std::string	_wired;
	std::string	_unused;

public:

	RAMModule();
	RAMModule(RAMModule const &other);
	~RAMModule();
	RAMModule	& operator=(RAMModule const &other);

	void				set_data();
	char const *	 	get_size() const;
	char const *	 	get_type() const;
	char const *	 	get_speed() const;
	char const *	 	get_used() const;
	char const *	 	get_wired() const;
	char const *	 	get_unused() const;
};


#endif 
