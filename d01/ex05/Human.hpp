/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 08:45:01 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/03 08:45:07 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
#define HUMAN_HPP
#include "Brain.hpp"

class Human
{
	Brain const _brain;
public:
	Human();
	~Human();
	std::string identify() const;
	Brain getBrain() const;
};

#endif
