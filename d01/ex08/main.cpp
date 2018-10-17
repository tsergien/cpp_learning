/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 11:53:00 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/03 11:53:01 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main()
{
	Human h;
	std::string target;
	target = "TARGET";
	h.action("meleeAttack", target);
	h.action("rangedAttack", target);
	h.action("intimidatingShout", target);
	h.action("meleeAttack", target);

	return 0;
}
