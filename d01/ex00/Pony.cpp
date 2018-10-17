/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 12:49:49 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/03 08:38:57 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony()
{
	_name = "Rainbow";
	std::cout << "\x1b[38;5;205mCongratulations! New pony named " << _name << " born ^^\n\033[0m";
}
Pony::Pony(std::string name) :_name(name)
{
	std::cout << "\x1b[38;5;205mCongratulations! New pony named " << _name <<  " born ^^\n\033[0m";
}

Pony::~Pony()
{
	std::cout << "\x1b[38;5;74mSad news: pony "  << _name << " died\n\033[0m";
}

void	Pony::make_rainbow()
{
	for (int i = 0; i < 5; i++)
	{	std::cout << "\x1b[38;5;196mR_\x1b[38;5;166mA_\x1b[38;5;11mI_";
		std::cout << "\x1b[38;5;118mN_\x1b[38;5;26mB_\x1b[38;5;17mO_\x1b[38;5;55mW_\n\033[0m";
	}
}
