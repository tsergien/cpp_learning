/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:16:27 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/06 14:16:30 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"
#include "PlasmaRifle.hpp"
#include "SuperMutant.hpp"
#include "Character.hpp"
#include "RadScorpion.hpp"

// int main()
// {
// 	PowerFist* pf = new PowerFist();
// 	PlasmaRifle* pr = new PlasmaRifle();
// 	RadScorpion* rs = new RadScorpion();;
// 	SuperMutant* sm = new SuperMutant();
// 	Character* me = new Character("T");

// 	me->equip(pr);
// 	std::cout << *me;

// 	me->equip(pf);
// 	std::cout << *me;

// 	me->attack(rs);
// 	me->attack(rs);
// 	me->attack(sm);
// 	me->attack(sm);

// 	std::cout << *me;



// 	return 0;
// }

int main()
{
	Character* zaz = new Character("zaz");
	std::cout << *zaz;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	
	zaz->equip(pr);
	std::cout << *zaz;
	
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	return 0;
}