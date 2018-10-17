/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 08:44:02 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/03 08:44:04 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int main()
{
	{
		ZombieHorde rr(5);	
		rr.announce();
	}
	std::cout << "After block 1\n";
	{
		ZombieHorde rr(0);	
		rr.announce();
	}
	std::cout << "After block 2\n";
	{
		ZombieHorde rr(1);
		rr.announce();
	}
	std::cout << "After block 3\n";

	return 0;
}
