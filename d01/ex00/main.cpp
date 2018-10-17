/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 12:50:13 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/03 08:38:46 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	ponyOnTheHeap(std::string name)
{
	Pony* new_pony = new Pony(name);
	new_pony->make_rainbow();
	delete new_pony;
}
void	ponyOnTheStack(std::string name)
{
	Pony pony_stack(name);
	pony_stack.make_rainbow();
}

void	ponyOnTheHeap()
{
	Pony* new_pony = new Pony();
	new_pony->make_rainbow();
	delete new_pony;
}
void	ponyOnTheStack()
{
	Pony pony_stack;
	pony_stack.make_rainbow();
}

int main()
{
	std::cout << "Before calling ponyOnTheHeap: \n";
	ponyOnTheHeap();
	ponyOnTheHeap("Mabel_gilt");
	std::cout << "After calling ponyOnTheHeap. \n";
	std::cout << "Before calling ponyOnTheStack: \n";
	ponyOnTheStack();
	ponyOnTheStack("Dipper");
	std::cout << "After calling ponyOnTheStack. \n";
	return 0;
}
