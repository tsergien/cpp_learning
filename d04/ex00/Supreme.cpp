/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Supreme.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:56:08 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 13:56:09 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Supreme.hpp"

Supreme::Supreme(){}

Supreme::~Supreme(){
	std::cout << "Ciao...\n";	
}

Supreme::Supreme(std::string name) : Victim(name) {
	std::cout << "Hello.\n";
}

Supreme::Supreme(Supreme const & other){
	*this = other;
}

Supreme & Supreme::operator=(Supreme const & other){
	get_name() = other.get_name();
	return *this;
}

void Supreme::getPolymorphed() const{
	std::cout << get_name() << " has been turned into a pink pony but become a super cool butterfly !\n";
}

std::ostream & operator<<(std::ostream & os, Supreme const & rhs){
	os << "I'm "<< rhs.get_name() << " and I love people !\n";
	return os;
}

