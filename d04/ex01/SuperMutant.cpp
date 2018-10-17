/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:15:39 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 14:15:41 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant(): Enemy(170, "Super Mutant"){
	std::cout << "Gaaah. Me want smash heads !\n";
}
SuperMutant::SuperMutant(int hp, std::string const & type): Enemy(hp, type){
	std::cout << "Gaaah. Me want smash heads !\n";
}
SuperMutant::SuperMutant(SuperMutant const & other){
	*this = other;
}
SuperMutant const & SuperMutant::operator=(SuperMutant const & other){
	*((Enemy*)this) = other;
	return *this;
}
SuperMutant::~SuperMutant(){
	std::cout << "Aaargh ...\n";
}

void SuperMutant::takeDamage(int amount){
	Enemy::takeDamage(amount - 3);
}
