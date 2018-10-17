/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:15:56 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 14:15:57 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion(): Enemy(80, "Rad Scorpion"){
	std::cout << "* click click click *\n";
}

RadScorpion::RadScorpion(int hp, std::string const & type): Enemy(hp, type){
	std::cout << "* click click click *\n";
}

RadScorpion::RadScorpion(RadScorpion const & other){
	*this = other;
}
RadScorpion const & RadScorpion::operator=(RadScorpion const & other){
	*((Enemy*)this) = other;
	return *this;
}
RadScorpion::~RadScorpion(){
	std::cout << "* SPROTCH *\n";
}
void RadScorpion::takeDamage(int amount){
	Enemy::takeDamage(amount);
}
