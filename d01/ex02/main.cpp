/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 08:40:04 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/03 08:40:08 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int main()
{
	ZombieEvent party;
	Zombie *z1 = party.newZombie("Arnold");
	Zombie *z2 = party.newZombie("Amanda");
	Zombie *z3 = party.newZombie("Alis");
	Zombie z4;

	z4.announce();
	z1->announce();
	party.setZombieType(z1);
	z2->announce();
	party.setZombieType(z1);
	z3->announce();
	party.randomChump();
	party.randomChump();

	party.setZombieType(z1);
	z1->announce();

	delete z1;
	delete z2;
	delete z3;
	return 0;
}
