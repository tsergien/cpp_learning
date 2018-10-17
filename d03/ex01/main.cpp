/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 09:10:59 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/05 09:11:01 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#define PLAYERS_NUM_F 5

bool someone_alive(FragTrap ar[PLAYERS_NUM_F], ScavTrap & s)
{
	int c = 0;
	if (s.is_alive())
		c++;
	for (int i = 0; i < PLAYERS_NUM_F; i++)
		if (ar[i].is_alive())
			c++;
	if (c < 2)
		return 0;
	return 1;
}

int main()
{
	srand ( time(NULL) );
	int n = PLAYERS_NUM_F;
	std::string names_pool[8] = {"Jack", "Athena", "Carl", "Tom", "Hardi", "Venom", "Tony", "Stark"};
	FragTrap f[PLAYERS_NUM_F];
	ScavTrap s(names_pool[rand() % 8]);
	for (int i = 0; i < n; i++)
		f[i].set_name(names_pool[(rand() + i) % 8]);

	std::cout << "\x1b[38;5;207m\t\t************ ________ ************\n\033[0m";
	std::cout << "\x1b[38;5;207m\t\t************ ________ ************\n\033[0m";
	std::cout << "\x1b[38;5;207m\t\t************ ________ ************\n\033[0m";
	std::cout << "\x1b[38;5;207m\t\t************ THE GAME ************\n\033[0m";
	std::cout << "\x1b[38;5;207m\t\t************ ________ ************\n\033[0m";
	std::cout << "\x1b[38;5;207m\t\t************ ________ ************\n\033[0m";
	std::cout << "\x1b[38;5;207m\t\t************ ________ ************\n\033[0m";

	while (someone_alive(f, s))
	{
		int ind = rand() % PLAYERS_NUM_F;
		int ind2 = rand() % PLAYERS_NUM_F;
		if (ind == ind2) ind2 = (ind2 + 1) % PLAYERS_NUM_F;
		f[ind].vaulthunter_dot_exe(f[ind2].get_name());
		f[ind2].takeDamage(rand() % 30);
		
		s.challengeNewcomer(f[ind].get_name());
		f[ind].takeDamage(rand() % 50);

		f[ind2].vaulthunter_dot_exe(s.get_name());
		s.takeDamage(rand() % 10);

		if (rand() % 2)
			s.beRepaired(rand() % 5);
		f[rand() % PLAYERS_NUM_F].beRepaired(rand() % 20);
	}
	for (int i = 0; i < n; i++)
		if (f[i].is_alive())
			std::cout << "------------------> And the winner is " << f[i].get_name() << \
			" with level: " << f[i].get_level() << std::endl;


	return 0;
}
