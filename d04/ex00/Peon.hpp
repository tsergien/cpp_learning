/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:57:41 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 13:57:42 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
#define PEON_HPP
#include <iostream>
#include "Victim.hpp"
class Peon : public Victim
{
public:
	Peon();
	~Peon();
	Peon(std::string name);
	Peon(Peon const & other);
	Peon & operator=(Peon const & other);

	void virtual getPolymorphed() const;
};

#endif
