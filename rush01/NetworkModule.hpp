#ifndef NETWORKMODULE_HPP
#define NETWORKMODULE_HPP
#include "IMonitorModule.hpp"

class NetworkModule : public IMonitorModule
{
	std::string		_in;
	std::string		_out;
public:

	NetworkModule();
	NetworkModule(NetworkModule const &other);
	~NetworkModule();
	NetworkModule    &operator=(NetworkModule const &other);

	void				set_data();
	char const *	 	get_in() const;
	char const *	 	get_out() const;
};


#endif 
