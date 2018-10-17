/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 09:14:51 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/04 09:14:53 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
	int					_value;
	static const int	_fbits;
public:
	Fixed();
	Fixed(const int val);
	Fixed(const float val);
	~Fixed();
	Fixed(Fixed const & other);
	int		getRawBits() const;
	void	setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;

	Fixed & operator=(Fixed const & other);

	Fixed operator+(Fixed const & other) const;
	Fixed operator-(Fixed const & other) const;
	Fixed operator*(Fixed const & other) const;
	Fixed operator/(Fixed const & other) const;

	bool operator>(Fixed const & other) const;
	bool operator<(Fixed const & other) const;
	bool operator>=(Fixed const & other) const;
	bool operator<=(Fixed const & other) const;
	bool operator==(Fixed const & other) const;
	bool operator!=(Fixed const & other) const;

	Fixed & operator++();//prefix
	Fixed operator++(int);//postfix
	Fixed & operator--();
	Fixed operator--(int);
	static Fixed &	max(Fixed & a, Fixed & b);
	static Fixed const &	max(Fixed const & a, Fixed const & b);
	static Fixed &	min(Fixed & a, Fixed & b);
	static Fixed const &	min(Fixed const & a, Fixed const & b);
};

std::ostream& operator<<(std::ostream & o, Fixed const & rhs);

#endif
