/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:16:44 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/03 14:16:45 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int main(int argc, char **av)
{
	if (argc < 2)
		return 0;
	Logger vahter(av[1]);
	vahter.log("console", "hello handsome!");
	vahter.log("console", "hello handsome you're the best!");
	vahter.log("console", "h!.");
	vahter.log("console", "^^.");
	vahter.log("file", "ciao.");
	vahter.log("file", "tam tam tam.");
	vahter.log("file", "go pony.");
	vahter.log("file", "arrividerci.");

	return 0;
}
