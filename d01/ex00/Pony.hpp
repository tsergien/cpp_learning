/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 12:49:56 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/02 12:49:58 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP
# include <iostream>
# include <string>

class Pony
{
	std::string _name;
public:
	Pony();
	Pony(std::string);
	~Pony();
	void	make_rainbow();
};

#endif
