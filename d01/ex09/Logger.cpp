/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  Logger.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:16:27 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/03 14:17:10 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
Logger::Logger(std::string name) : _name(name){}

Logger::~Logger(){}

std::string	Logger::makeLogEntry(std::string const message) const
{
	time_t t;
	time(&t);
	std::string res = ctime(&t);
	res = res.substr(0, res.size() - 1);
	res.append(" ");
	res.append(message);
	return res;
}

void	Logger::logToConsole(std::string const s) const
{
	std::cout << s << std::endl;
}
void	Logger::logToFile(std::string const s) const
{
	std::ofstream outs;
	outs.open(_name, std::ios_base::app);
	outs << s << std::endl;
	outs.close();
}

void	Logger::log(std::string const & dest, std::string const & message)
{
	void	(Logger::*func_ptr[2]) (std::string const s) const;
	func_ptr[0] = &Logger::logToConsole;
	func_ptr[1] = &Logger::logToFile;
	std::string ind[] = {"console", "file"};
	std::ofstream outs;
	outs.open("my_logs", std::ios_base::app);
	for (int i = 0; i < 2; i++)
		if (ind[i] == dest)
		{
			(this->*func_ptr[i])(message);
			outs << makeLogEntry(message) << " to " << dest << std::endl;
			outs.close();
			break;
		}
	
}
