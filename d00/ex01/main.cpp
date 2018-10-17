/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 12:43:07 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/01 12:43:09 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Notebook.hpp"

std::string	to_up(std::string s)
{
	std::string res;
	int n = s.size();
	for (int i = 0; i < n; i++)
	{

		if (s[i] >= 'a' && s[i] <= 'z')
			res.push_back(s[i] - 32);
		else
			res.push_back(s[i]);		
	}
	return res;
}

int		main()
{
	Notebook	notebook;
	std::string command;
	std::cout << "\x1b[38;5;32mYou can input commands:\n*SEARCH\n*ADD\n*EXIT\n\033[0m";
	while (std::getline(std::cin, command))
	{
		if (to_up(command).compare("ADD") == 0)
			notebook.add();
		else if (to_up(command).compare("SEARCH") == 0)
			notebook.search();
		else if (to_up(command).compare("EXIT") == 0)
			return (0);
		else
			std::cout << "\x1b[38;5;32mYou can input commands:\n*SEARCH\n*ADD\n*EXIT\n\033[0m";
	}
	return 0;
}