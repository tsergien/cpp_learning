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
#include "NinjaTrap.hpp"

#define PLAYERS_NUM_F 2

int someone_alive(FragTrap ar[PLAYERS_NUM_F], ScavTrap & s, NinjaTrap & ni)
{
	int c = 0;
	if (s.is_alive())
		c++;
	if (ni.is_alive())
		c++;
	for (int i = 0; i < PLAYERS_NUM_F; i++)
		if (ar[i].is_alive())
			c++;
	return c;
}

int main()
{
	srand ( time(NULL) );
	int n = PLAYERS_NUM_F;
	std::string names_pool[8] = {"Jack", "Athena", "Carl", "Tom", "Hardi", "Venom", "Tony", "Stark"};
	FragTrap f[PLAYERS_NUM_F];
	ScavTrap s(names_pool[rand() % 8]);
	NinjaTrap ni("Micelangelo");
	for (int i = 0; i < n; i++)
		f[i].set_name(names_pool[(rand() + i) % 8]);

	std::cout << "\x1b[38;5;207m\t\t************ ________ ************\n\033[0m";
	std::cout << "\x1b[38;5;207m\t\t************ ________ ************\n\033[0m";
	std::cout << "\x1b[38;5;207m\t\t************ ________ ************\n\033[0m";
	std::cout << "\x1b[38;5;207m\t\t************ THE GAME ************\n\033[0m";
	std::cout << "\x1b[38;5;207m\t\t************ ________ ************\n\033[0m";
	std::cout << "\x1b[38;5;207m\t\t************ ________ ************\n\033[0m";
	std::cout << "\x1b[38;5;207m\t\t************ ________ ************\n\033[0m";

	while (someone_alive(f, s, ni) > 1)
	{
		std::cout << "\t\t\t******* ********** *******\n";
		std::cout << "\t\t\t******* NEXT ROUND *******\n";
		std::cout << "\t\t\t******* ********** *******\n";
		
		int ind = rand() % PLAYERS_NUM_F;
		int ind2 = rand() % PLAYERS_NUM_F;
		if (ind == ind2) ind2 = (ind2 + 1) % PLAYERS_NUM_F;
		f[ind].vaulthunter_dot_exe(f[ind2].get_name());
		f[ind2].takeDamage(rand() % 30);
		
		s.challengeNewcomer(f[ind].get_name());
		f[ind].takeDamage(rand() % 50);

		f[ind2].vaulthunter_dot_exe(s.get_name());
		s.takeDamage(rand() % 10);

		ni.ninjaShoeBox(f[ind]);
		f[ind].takeDamage(rand() % 50);

		f[ind].vaulthunter_dot_exe(ni.get_name());
		ni.takeDamage(rand() % 10);

		if (rand() % 2)
			s.beRepaired(rand() % 5);
		if (rand() % 2)
		ni.beRepaired(rand() % 5);
		f[rand() % PLAYERS_NUM_F].beRepaired(rand() % 20);

		for (int j = 0; j < PLAYERS_NUM_F; j++)
			std::cout << f[j].get_name() << "\t: energy = " << f[j].get_energy() <<\
			", HP = " << f[j].get_hp() << "\n";
		std::cout << s.get_name() << "\t: energy = " << s.get_energy() <<\
			", HP = " << s.get_hp() << "\n";
		std::cout << ni.get_name() << "\t: energy = " << s.get_energy() <<\
			", HP = " << ni.get_hp() << "\n";
	}

	if (s.is_alive())
		std::cout << "\x1b[38;5;196m------------------> And the winner is " << s.get_name() << \
			" with level: " << s.get_level() << "\n\033[0m";
	else if (ni.is_alive())
		std::cout << "\x1b[38;5;196m------------------> And the winner is " << ni.get_name() << \
			" with level: " << ni.get_level() << "\n\033[0m";
	for (int i = 0; i < n; i++)
		if (f[i].is_alive())
			std::cout << "\x1b[38;5;196m------------------> And the winner is " << f[i].get_name() << \
			" with level: " << f[i].get_level() << "\n\033[0m";
	if (!someone_alive(f, s, ni))
		std::cout << "\x1b[38;5;196m-------------------->NO ONE SURVIVED.\n\033[0m";
	return 0;
}
