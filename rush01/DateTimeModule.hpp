#ifndef DATETIMEMODULE_HPP
#define DATETIMEMODULE_HPP
#include "IMonitorModule.hpp"

class DateTimeModule : public IMonitorModule
{
	std::string	_date;
	std::string	_time;
public:

	DateTimeModule();
	DateTimeModule(DateTimeModule const &other);
	~DateTimeModule();

	DateTimeModule	&operator=(DateTimeModule const &other);

	void				set_data();
	char const *	 	get_date() const;
	char const *	 	get_time() const;
};


#endif //DATETIMEMODULE_HPP
