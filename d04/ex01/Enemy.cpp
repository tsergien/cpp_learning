/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:15:03 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 14:15:04 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(){}
Enemy::Enemy(int hp, std::string const & type) : _hp(hp), _type(type){}
Enemy::~Enemy(){}

Enemy::Enemy(Enemy const & other){
	*this = other;
}

Enemy const & Enemy::operator=(Enemy const & other){
	_hp = other.getHP();
	_type = other.getType();
	return *this;
}

std::string const & Enemy::getType() const{return _type;}
int Enemy::getHP() const{return _hp;}

void Enemy::takeDamage(int amount){
	if (amount > 0)
		_hp -= amount;
}
