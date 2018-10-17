/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Notebook.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:56:56 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/01 15:57:01 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOTEBOOK_HPP
# define NOTEBOOK_HPP
# include "Person.hpp"

class	Notebook
{
	Person		contacts_[8];
	static int instances_;
public:
	Notebook();
	~Notebook();
	int		add();
	void	search();
};

#endif
