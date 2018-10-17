/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 08:44:55 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/03 08:44:57 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(): _brain(){}
Human::~Human(){}

std::string Human::identify() const
{
	return _brain.identify();
}

Brain Human::getBrain() const
{
	return _brain;
}
