/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 11:52:32 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/03 11:52:45 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(){}
Human::~Human(){}

void Human::meleeAttack(std::string const & target)
{
	std::cout << "meleeAttack fun called." << std::endl;
}
void Human::rangedAttack(std::string const & target)
{
	std::cout << "rangedAttack fun called."<< std::endl;
}
void Human::intimidatingShout(std::string const & target)
{
	std::cout << "intimidatingShout fun called."<< std::endl;
}
void Human::action(std::string const & action_name, std::string const & target)
{
	std::string f_str[] = {"meleeAttack", "rangedAttack", "intimidatingShout"};
	void (Human::*func_ptr[3]) (std::string const & target);
	func_ptr[0] = &Human::meleeAttack;
	func_ptr[1] = &Human::rangedAttack;
	func_ptr[2] = &Human::intimidatingShout;
	for (int i = 0; i < 2; i++)
		if (f_str[i] == action_name)
		{
			(this->*func_ptr[i])(target);
			break;
		}
}
