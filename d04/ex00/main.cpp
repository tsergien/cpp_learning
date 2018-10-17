/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:58:01 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 13:58:02 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Supreme.hpp"

int main()
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	std::cout << robert << jim << joe;
	
	robert.polymorph(jim);
	robert.polymorph(joe);
	
	return 0;
}

// int main()
// {
// 	Sorcerer robert("King", "the Magnificent");
// 	Victim jim("el");
// 	Peon joe("tom");
// 	Supreme g("sup");
// 	std::cout << robert << jim << joe << g;
	
// 	robert.polymorph(jim);
// 	robert.polymorph(joe);
// 	robert.polymorph(g);
// 	return 0;
// }
