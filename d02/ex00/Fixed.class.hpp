/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:23:42 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/03 16:23:43 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
	int					_value;
	static const int	_fbits;
public:
	Fixed();
	~Fixed();
	Fixed(Fixed const & other);
	Fixed & operator=(Fixed const & other);
	int		getRawBits() const;
	void	setRawBits(int const raw);
};

#endif
