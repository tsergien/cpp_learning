/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:23:51 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/03 16:23:53 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

const int Fixed::_fbits = 8;

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

Fixed::Fixed(Fixed const & other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed & Fixed::operator=(Fixed const & other)
{
	std::cout << "Assignation operator called\n";
	this->setRawBits(other.getRawBits());
	return *this;
}
