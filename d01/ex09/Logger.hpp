/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:16:37 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/03 14:16:39 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <time.h> 

class Logger
{
	std::string _name;
	void		logToConsole(std::string const s) const;
	void		logToFile(std::string const s) const;
	std::string	makeLogEntry(std::string const mesage) const;
public:
	Logger(std::string name);
	Logger();
	~Logger();
	void	log(std::string const & dest, std::string const & message);
};

#endif

