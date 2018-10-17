/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 08:39:29 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/03 08:39:32 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
	std::string NameArray[10] = { "Iwalker", "Pain", "Runn", "Naruto", "Itachi",\
	"Tobi", "Madara", "Voodoo", "Danzou", "Kakashi" };
	srand(time(0));
	_name = NameArray[rand() % 8 + rand() % 2];
}

Zombie::~Zombie(){
	std::cout << "\x1b[38;5;196mZombie " << _name << " (" << _type  << ") destroyed\n\033[0m";
}

Zombie::Zombie(std::string name, std::string type): _name(name), _type(type){}

void	Zombie::announce()
{
	std::cout << _name << " (" << _type << ") Braiiiiiiinnnnnnnnssss...\n";
}

void	Zombie::set_name(std::string name)
{
	_name = name;
}
void	Zombie::set_type(std::string type)
{
	_type = type;
}
