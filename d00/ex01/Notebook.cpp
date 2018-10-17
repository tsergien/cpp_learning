/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Notebook.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:42:28 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/01 13:42:30 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Notebook.hpp"


Notebook::Notebook(){}

Notebook::~Notebook(){}

int Notebook::instances_ = 0;

int	Notebook::add()
{
	std::string s;
	if (instances_ + 1  > 8)
	{
		std::cout << "\x1b[38;5;196mYou can't add more than 8 contacts, sorry.\033[0m" << std::endl;
		return 0;
	}
	instances_++;
	std::cout << "Enter your first name: ";
	std::getline(std::cin, s);
	contacts_[instances_ - 1].set_fn(s);
	std::cout << "Enter your last name: ";
	std::getline(std::cin, s);
	contacts_[instances_ - 1].set_ln(s);
	std::cout << "Enter your nickname: ";
	std::getline(std::cin, s);
	contacts_[instances_ - 1].set_nick(s);
	std::cout << "Enter your login: ";
	std::getline(std::cin, s);
	contacts_[instances_ - 1].set_login(s);
	std::cout << "Enter your postal address: ";
	std::getline(std::cin, s);
	contacts_[instances_ - 1].set_address(s);
	std::cout << "Enter your postal email: ";
	std::getline(std::cin, s);
	contacts_[instances_ - 1].set_email(s);
	std::cout << "Enter your postal phone number: ";
	std::getline(std::cin, s);
	contacts_[instances_ - 1].set_phone_num(s);
	std::cout << "Enter your postal birthday date: ";
	std::getline(std::cin, s);
	contacts_[instances_ - 1].set_birthday(s);
	std::cout << "Enter your postal favorite meal: ";
	std::getline(std::cin, s);
	contacts_[instances_ - 1].set_fav_meal(s);
	std::cout << "Enter your postal undearwear color: ";
	std::getline(std::cin, s);
	contacts_[instances_ - 1].set_underwear(s);
	std::cout << "Enter your postal darkest_secret: ";
	std::getline(std::cin, s);
	contacts_[instances_ - 1].set_darkest_secret(s);
	std::cout << std::endl;
	return 1;
}

void	Notebook::search()
{
	int id;
	if (instances_ > 0 && instances_ < 9)
		contacts_[0].info_header();
	for (int i = 0; i < instances_; i++)
		contacts_[i].info();
	std::cout << "Enter id person you want to see detail information: ";
	std::string id_s;
	while (std::cin >> id_s)
	{
		if (id_s.size() != 1 || !isdigit(id_s[0]))
			std::cout << "\x1b[38;5;196mInvalid id!\033[0m\n\x1b[38;5;32mEnter id again: \033[0m";
		else
		{
			id = (int)id_s[0] - 48;
			if (id < 1 || id > instances_)
				std::cout << "\x1b[38;5;196mInvalid id!\033[0m\n\x1b[38;5;32mEnter id again: \033[0m";
			else
				break ;
		}
	}
	contacts_[id - 1].full_info();
}
