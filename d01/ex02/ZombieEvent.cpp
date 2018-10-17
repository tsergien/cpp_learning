/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 08:39:48 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/03 08:39:53 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(){}
ZombieEvent::~ZombieEvent()
{
}

void	ZombieEvent::setZombieType(Zombie *obj)
{
	obj->set_type(_type);
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	Zombie* z = new Zombie();
	z->set_name(name);
	z->set_type(_type);
	return z;
}

void	ZombieEvent::randomChump()
{
	Zombie z;
	std::string NameArray[10] = { "Iwalker", "Pain", "Runn", "Naruto", "Itachi",\
	"Tobi", "Madara", "Voodoo", "Danzou", "Kakashi" };
	std::string TypeArray[10] = { "walker", "stalker", "runner", "voodoo", "crawler",\
	"burster", "spitter", "tank", "exploder", "ghoul" };
	srand(time(0));
	z.set_name(NameArray[rand() % 8 + rand() % 2]);
	srand(time(0));
	z.set_type(TypeArray[rand() % 8 + rand() % 2]);
	std::cout << "\x1b[38;5;213m";
	z.announce();
	std::cout << "\033[0m";
}
