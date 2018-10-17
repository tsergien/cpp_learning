/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Person.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 12:45:58 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/01 12:46:01 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSON_HPP
# define PERSON_HPP
# include <iostream>
# include <string>
# include <iomanip>

class	Person
{
	static int	inst_;
	int			id_;
	std::string first_name_;
	std::string last_name_;
	std::string nick_;
	std::string login_;
	std::string address_;
	std::string email_;
	std::string phone_num_;
	std::string birthday_;
	std::string fav_meal_;
	std::string underwear_;
	std::string darkest_secret_;
public:
	void	set_fn(std::string s);
	void	set_ln(std::string s);
	void	set_nick(std::string s);
	void	set_login(std::string s);
	void	set_address(std::string s);
	void	set_email(std::string s);
	void	set_phone_num(std::string s);
	void	set_birthday(std::string s);
	void	set_fav_meal(std::string s);
	void	set_underwear(std::string s);
	void	set_darkest_secret(std::string s);
	std::string	get_fn() const;
	std::string	get_ln() const;
	std::string	get_nick() const;
	std::string	get_login() const;
	std::string	get_address() const;
	std::string	get_email() const;
	std::string	get_phone_num() const;
	std::string	get_birthday() const;
	std::string	get_fav_meal() const;
	std::string	get_underwear() const;
	std::string	get_darkest_secret() const;
	int		get_id() const;
	Person();
	~Person();
	void		full_info() const;
	void		info() const;
	void		info_header() const;
};

#endif
