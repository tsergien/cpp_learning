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
#define PLAYERS_NUM 3

bool someone_alive(FragTrap ar[PLAYERS_NUM])
{
	int c = 0;
	for (int i = 0; i < PLAYERS_NUM; i++)
		if (ar[i].is_alive())
			c++;
	if (c < 2)
		return 0;
	return 1;
}

int main()
{
	srand ( time(NULL) );
	FragTrap f1("Jack");
	FragTrap f2("Claptrap");
	FragTrap f3(f1);

	f2.vaulthunter_dot_exe(f1.get_name());
	FragTrap f4 = f2;

	f1.vaulthunter_dot_exe(f2.get_name());
	f1.vaulthunter_dot_exe(f2.get_name());
	f1.vaulthunter_dot_exe(f2.get_name());
	f1.vaulthunter_dot_exe(f2.get_name());
	f1.vaulthunter_dot_exe(f2.get_name());
	f3.vaulthunter_dot_exe(f1.get_name());

	FragTrap f5("Dust");


	int n = PLAYERS_NUM;
	std::string names_pool[8] = {"Jack", "John", "Carl", "Tom", "Hardi", "Venom", "Tony", "Stark"};
	FragTrap f[PLAYERS_NUM];
	for (int i = 0; i < n; i++)
		f[i].set_name(names_pool[(rand() + i) % 8]);

	std::cout << "\x1b[38;5;207m\t\t************ ________ ************\n\033[0m";
	std::cout << "\x1b[38;5;207m\t\t************ ________ ************\n\033[0m";
	std::cout << "\x1b[38;5;207m\t\t************ ________ ************\n\033[0m";
	std::cout << "\x1b[38;5;207m\t\t************ THE GAME ************\n\033[0m";
	std::cout << "\x1b[38;5;207m\t\t************ ________ ************\n\033[0m";
	std::cout << "\x1b[38;5;207m\t\t************ ________ ************\n\033[0m";
	std::cout << "\x1b[38;5;207m\t\t************ ________ ************\n\033[0m";

	while (someone_alive(f))
	{
		int ind = rand() % PLAYERS_NUM;
		int ind2 = rand() % PLAYERS_NUM;
		if (ind == ind2) ind2 = (ind2 + 1) %PLAYERS_NUM;
		f[ind].vaulthunter_dot_exe(f[ind2].get_name());
		f[ind2].takeDamage(rand() % 30);
		f[rand() % PLAYERS_NUM].beRepaired(rand() % 20);
	}
	for (int i = 0; i < n; i++)
		if (f[i].is_alive())
			std::cout << "\n\n--------------> And the winner is " << f[i].get_name() << \
			" with level: " << f[i].get_level() << std::endl;


	return 0;
}

