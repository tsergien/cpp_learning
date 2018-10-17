/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 08:39:56 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/03 08:39:58 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP
# include "Zombie.hpp"

class ZombieEvent
{
	std::string _type;
public:
	ZombieEvent();
	~ZombieEvent();
	void	setZombieType(Zombie *obj);
	Zombie* newZombie(std::string name);
	void	randomChump();
};

#endif
