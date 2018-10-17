/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Person.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 12:45:47 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/01 12:45:49 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Person.hpp"

int	Person::inst_ = 0;

Person::Person(){
	++inst_;
	id_ = inst_;
}

Person::~Person(){}

void		Person::full_info() const
{
	std::cout << "First name: " << first_name_ << std::endl;
	std::cout << "Last name: " << last_name_ << std::endl;
	std::cout << "Nickname: " << nick_ << std::endl;
	std::cout << "Login: " << login_ << std::endl;
	std::cout << "Postal address: " << address_ << std::endl;
	std::cout << "Email: " << email_ << std::endl;
	std::cout << "Phone number: " << phone_num_ << std::endl;
	std::cout << "Birthday date: " << birthday_ << std::endl;
	std::cout << "Favorite meal: " << fav_meal_ << std::endl;
	std::cout << "Underwear color: " << underwear_ << std::endl;
	std::cout << "Darkest secret: " << darkest_secret_ << std::endl;
	std::cout << std::endl;
}

void		Person::info_header() const
{
	std::cout << std::setw(10);
	std::cout << std::internal << "ID" << "|";
	std::cout << std::setw(10);
	std::cout << std::internal << "FIRST NAME" << "|";
	std::cout << std::setw(10);
	std::cout << std::internal << "LAST NAME" << "|";
	std::cout << std::setw(10);
	std::cout << std::internal << "NICKNAME" << "|";
	std::cout << std::endl;
}

void		Person::info() const
{
	std::string s;
	std::cout << std::setw(10);
	std::cout << std::right << id_ << "|";
	s = first_name_;
	if (s.size() > 10)
	{
		s.resize(9);
		s.append(".");
	}
	std::cout << std::setw(10);
	std::cout << std::right << s << "|";
	s = last_name_;
	if (s.size() > 10)
	{
		s.resize(9);
		s.append(".");
	}
	std::cout << std::setw(10);
	std::cout << std::right << last_name_ << "|";
	s = nick_;
	if (s.size() > 10)
	{
		s.resize(9);
		s.append(".");
	}
	std::cout << std::setw(10);
	std::cout << std::right << nick_ <<  "|";
	std::cout << std::endl;
}
void	Person::set_fn(std::string s)
{
	first_name_ = s;
}
void	Person::set_ln(std::string s)
{
	last_name_ = s;
}
void	Person::set_nick(std::string s)
{
	nick_ = s;
}
void	Person::set_login(std::string s)
{
	login_ = s;
}
void	Person::set_address(std::string s)
{
	address_ = s;
}
void	Person::set_email(std::string s)
{
	email_ = s;
}
void	Person::set_phone_num(std::string s)
{
	phone_num_ = s;
}
void	Person::set_birthday(std::string s)
{
	birthday_ = s;
}
void	Person::set_fav_meal(std::string s)
{
	fav_meal_ = s;
}
void	Person::set_underwear(std::string s)
{
	underwear_ = s;
}
void	Person::set_darkest_secret(std::string s)
{
	darkest_secret_ = s;
}
int		Person::get_id() const
{
	return id_;
}
std::string	Person::get_fn() const
{
	return first_name_;
}
std::string	Person::get_ln() const
{
	return last_name_;
}
std::string	Person::get_nick() const
{
	return nick_;
}
std::string	Person::get_login() const
{
	return login_;
}
std::string	Person::get_address() const
{
	return address_;
}
std::string	Person::get_email() const
{
	return email_;
}
std::string	Person::get_phone_num() const
{
	return phone_num_;
}
std::string	Person::get_birthday() const
{
	return birthday_;
}
std::string	Person::get_fav_meal() const
{
	return fav_meal_;
}
std::string	Person::get_underwear() const
{
	return underwear_;
}
std::string	Person::get_darkest_secret() const
{
	return darkest_secret_;
}