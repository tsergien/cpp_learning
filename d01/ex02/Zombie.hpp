/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 08:39:40 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/03 08:39:42 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# include <string>

class Zombie
{
	std::string _name;
	std::string _type;
public:
	Zombie();
	~Zombie();
	Zombie(std::string name, std::string type);
	void	set_name(std::string name);
	void	set_type(std::string type);
	void	announce();
};

#endif
