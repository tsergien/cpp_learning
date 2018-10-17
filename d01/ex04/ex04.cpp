/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 08:44:17 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/03 08:44:19 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string s = "HI THIS IS BRAIN";
	std::string* s_ptr = &s;
	std::string& s_ref = s;

	std::cout << *s_ptr << std::endl;
	std::cout << s_ref << std::endl;
	return 0;
}
