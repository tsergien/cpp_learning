/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:56:24 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 13:56:26 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
#define SORCERER_HPP
#include <iostream>
#include "Victim.hpp"
#include "Peon.hpp"
#include "Supreme.hpp"

class Sorcerer
{
	std::string _name;
	std::string _title;
	Sorcerer();
public:
	~Sorcerer();
	Sorcerer(std::string name, std::string title);
	Sorcerer(Sorcerer const & other);
	Sorcerer & operator=(Sorcerer const & other);
	std::string get_name() const;
	std::string get_title() const;

	void polymorph(Victim const & v) const;
	void polymorph(Peon const & v) const;
	void polymorph(Supreme const & v) const;
};

std::ostream & operator<<(std::ostream & os, Sorcerer const & rhs);

#endif
