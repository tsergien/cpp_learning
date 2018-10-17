/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 09:14:46 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/04 09:14:47 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

const int Fixed::_fbits = 8;

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int val) : _value(val << _fbits)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float val) : _value(roundf(val * (float)(1 << _fbits)))
{
	std::cout << "Float constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(Fixed const & other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
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

float Fixed::toFloat( void ) const
{
	return ((float)_value / (float)(1 << _fbits));
}

int Fixed::toInt( void ) const
{
	return (int)(_value >> _fbits);
}

Fixed & Fixed::operator=(Fixed const & other)
{
	std::cout << "Assignation operator called\n";
	_value = other._value;
	return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}
