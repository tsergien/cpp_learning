/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:15:06 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 14:15:07 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <iostream>

class Enemy
{
private:
	int _hp;
	std::string _type;
public:
	Enemy();
	Enemy(int hp, std::string const & type);
	Enemy(Enemy const & other);
	Enemy const & operator=(Enemy const & other);
	virtual ~Enemy();

	std::string const & getType() const;
	int getHP() const;
	virtual void takeDamage(int);
};

#endif

