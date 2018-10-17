/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Supreme.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:56:14 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 13:56:18 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPREME_HPP
#define SUPREME_HPP
#include <iostream>
#include "Victim.hpp"

class Supreme : public Victim
{
public:
	Supreme();
	~Supreme();
	Supreme(std::string name);
	Supreme(Supreme const & other);
	Supreme & operator=(Supreme const & other);

	void virtual getPolymorphed() const;
};

std::ostream & operator<<(std::ostream & os, Supreme const & rhs);

#endif

