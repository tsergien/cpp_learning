/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:57:37 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 13:57:38 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon(){}

Peon::~Peon(){
	std::cout << "Bleuark...\n";	
}

Peon::Peon(std::string name): Victim(name){
	std::cout << "Zog zog.\n";
}

Peon::Peon(Peon const & other){
	*this = other;
}

Peon & Peon::operator=(Peon const & other){
	get_name() = other.get_name();
	return *this;
}

void Peon::getPolymorphed() const{
	std::cout << get_name() << " has been turned into a pink pony !\n";
}

