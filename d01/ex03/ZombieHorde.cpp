/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 08:40:41 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/03 08:40:47 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) : _N(N), _zombie_bunch(new Zombie[N]){
	std::string NameArray[10] = { "Iwalker", "Pain", "Runn", "Naruto", "Itachi",\
	"Tobi", "Madara", "Voodoo", "Danzou", "Kakashi" };
	srand(time(0));
	for (int i = 0; i < N; i++)
		_zombie_bunch[i].set_name(NameArray[(i + rand()) % 10]);
}

ZombieHorde::~ZombieHorde()
{
	delete [] _zombie_bunch;
}

void	ZombieHorde::announce()
{
	for (int i = 0; i < _N; i++)
		_zombie_bunch[i].announce();
}
