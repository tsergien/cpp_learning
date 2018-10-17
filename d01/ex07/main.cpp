/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 08:36:59 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/03 08:37:02 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int 	error()
{
	std::cout << "Usage: ./replace filename nonempty_str1 nonempty_str2\n";
	return (0);
}

int main(int ac, char **av)
{
	if (ac < 4)
		return error();
	else
	{
		std::stringstream ss;
		std::ifstream ins(av[1]);
		std::string filename = av[1];
		filename.append(".replace");
		std::ofstream outs(filename);

		ss << ins.rdbuf();
		std::string s = ss.str();

		std::string s1;
		s1.assign(av[2]);
		std::string s2;
		s2.assign(av[3]);
		if (s1.empty() || s2.empty())
			return error();

		int pos = 0;
		while ((pos = s.find(s1, pos)) != (int)std::string::npos)
		{
			s.replace(pos, s1.size(), s2);
			pos += s2.size();
		}
		outs << s;
		outs.close();
		ins.close();
	}
	return 0;
}

