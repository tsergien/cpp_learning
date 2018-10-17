/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:16:14 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 14:16:15 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
private:
	std::string _name;
	int _ap;
	AWeapon *weapon;
public:
	Character();
	Character(std::string const & name);
	Character(Character const & other);
	Character const & operator=(Character const & other);
	~Character();

	void recoverAP();
	void equip(AWeapon* w);
	void attack(Enemy* e);
	std::string const & getName() const;
	int getAP() const;
	bool armed() const;
	AWeapon const * getWeapon() const;
};

std::ostream & operator<<(std::ostream & os, Character const & rhs);

#endif
