/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 09:10:59 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/05 09:11:01 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "SuperTrap.hpp"
#include "NinjaTrap.hpp"

int main()
{
	SuperTrap t("SUPREMEBEING");
	SuperTrap def;
	NinjaTrap ninj("Ninj");
	FragTrap frag("Frag");
	std::cout << "1 " << std::endl;
	t.rangedAttack("werfgb");
	std::cout << "2 " << std::endl;
	t.ninjaShoeBox(frag);
	std::cout << "3 " << std::endl;
	t.ninjaShoeBox(ninj);
	std::cout << "4 " << std::endl;
	t.vaulthunter_dot_exe("OLOL");
	std::cout << "6 " << std::endl;
	t.rangedAttack("werfgb");
	std::cout << "7 " << std::endl;
	return 0;
}

