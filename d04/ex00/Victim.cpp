/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:57:04 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 13:57:06 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(){}
Victim::~Victim(){
	std::cout << "Victim "<<_name << " just died for no apparent reason !\n";
}
Victim::Victim(std::string name): _name(name){
	std::cout << "Some random victim called " << _name << " just popped !\n";
}

Victim::Victim(Victim const & other){*this = other;}

Victim & Victim::operator=(Victim const & other){
	_name = other._name;
	return *this;
}

std::string Victim::get_name() const{return _name;}

std::ostream & operator<<(std::ostream & os, Victim const & rhs){
	os << "I'm "<< rhs.get_name() << " and I like otters !\n";
	return os;
}

void Victim::getPolymorphed() const{
	std::cout << _name << " has been turned into a cute little sheep !\n";
}
