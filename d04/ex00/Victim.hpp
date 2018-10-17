/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:57:12 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 13:57:15 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
#define VICTIM_HPP
#include <iostream>

class Victim
{
	std::string _name;
public:
	Victim();
	~Victim();
	Victim(std::string name);
	Victim(Victim const & other);
	Victim & operator=(Victim const & other);

	std::string get_name() const;
	void virtual getPolymorphed() const;
};

std::ostream & operator<<(std::ostream & os, Victim const & rhs);

#endif

