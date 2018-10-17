/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:56:29 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 13:56:54 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"


Sorcerer::~Sorcerer(){
	std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same !\n";

}
Sorcerer::Sorcerer(std::string name, std::string title): _name(name), _title(title){
	std::cout << _name << ", " << _title << ", is born !\n";
}

Sorcerer::Sorcerer(Sorcerer const & other){*this = other;}

Sorcerer & Sorcerer::operator=(Sorcerer const & other)
{
	_name = other._name;
	_title = other._title;
	return *this;
}

std::string Sorcerer::get_name() const{return _name;}
std::string Sorcerer::get_title() const{return _title;}

std::ostream & operator<<(std::ostream & os, Sorcerer const & rhs)
{
	os << "I am "<< rhs.get_name() << ", " << rhs.get_title() << \
	", and I like ponies !\n";
	return os;
}

void Sorcerer::polymorph(Victim const & v) const{
	v.getPolymorphed();
}

void Sorcerer::polymorph(Peon const & v) const{
	v.getPolymorphed();
}
