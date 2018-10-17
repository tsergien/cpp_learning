#ifndef IMONITORMODULE_HPP
#define IMONITORMODULE_HPP
#include <iostream>

class IMonitorModule {
public:
	virtual ~IMonitorModule(){}
	virtual void		set_data() = 0;
};

#endif
