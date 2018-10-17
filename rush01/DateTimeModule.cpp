#include "DateTimeModule.hpp"

DateTimeModule::DateTimeModule() : IMonitorModule() {}
DateTimeModule::DateTimeModule(DateTimeModule const &other){*this = other;}
DateTimeModule::~DateTimeModule(){}

DateTimeModule	& DateTimeModule::operator=(DateTimeModule const &other){
	_date = other._date;
	_time = other._time;
	return *this;
}

void				DateTimeModule::set_data()
{
	char buf[50];
	FILE * filestream = popen("date '+%Y-%M-%D %H:%m:%S'", "r");
	std::string s = fgets(buf, 50, filestream);
	_date = s.substr(0, 16);
	_time = s.substr(s.find(" ") + 1, 8);
	pclose(filestream);
}

char const *	 	DateTimeModule::get_date() const
{
	return _date.c_str();
}

char const *	 	DateTimeModule::get_time() const
{
	return _time.c_str();
}