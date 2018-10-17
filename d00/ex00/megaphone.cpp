/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:27:06 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/01 11:17:23 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main(int argc, char **argv)
{
	int shift = 'A' - 'a';
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		int n = 0;
		while (argv[i][n])
			n++;
		for (int j = 0; j < n; j++)
		{
			char temp = argv[i][j];
			if (temp >= 'a' && temp <= 'z')
				temp += shift;
			std::cout << temp;
		}
	}
	std::cout << std::endl;
	return 0;
}
