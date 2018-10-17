//
// Created by Andrii BYTKO on 13.10.2018.
//

#include "NetworkModule.hpp"

NetworkModule::NetworkModule(){}
NetworkModule::NetworkModule(NetworkModule const &other){*this = other;}
NetworkModule::~NetworkModule(){}
NetworkModule    & NetworkModule::operator=(NetworkModule const &other)
{
	_in = other._in;
	_out = other._out;
	return *this;
}

void				NetworkModule::set_data()
{
	char buf[50];
	FILE * filestream = popen("top", "r");
	std::string s;
	for (int i = 0; i < 13; i++)
		s = fgets(buf, 50, filestream);
	int ind = s.find("ets:") + 5;
	_in = s.substr(ind, s.find("in") - ind);
	ind = s.find("in, ") + 4;
	_out = s.substr(ind, s.find("M out") - ind);
	pclose(filestream);
}

char const *	 	NetworkModule::get_in() const
{
	return _in.c_str();
}
char const *	 	NetworkModule::get_out() const
{
	return _out.c_str();
}