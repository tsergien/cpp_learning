/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 17:00:02 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/03 17:00:04 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cerrno>

void	start_input()
{
	while (std::cout << std::cin.rdbuf())
	{
		std::cin.clear();
		std::cout.clear();

		freopen(NULL, "w", stdout);
		freopen(NULL, "r", stdin);
		break ;
	}
}

int main(int argc, char **argv)
{
	std::string av;
	if (argc == 1)
		start_input();
	for (int i = 1; i < argc; i++)
	{
		if ((std::string)argv[i] == (std::string)"-")
			start_input();
		else
		{
			std::ifstream ins(argv[i]);
			if (errno)
				std::cerr << "cat: " << argv[i] << ": " << strerror(errno) << std::endl;
			std::stringstream ss;
			ss << ins.rdbuf();
			std::string s = ss.str();
			std::cout << s;
			ins.close();
		}
	}
	return 0;
}
