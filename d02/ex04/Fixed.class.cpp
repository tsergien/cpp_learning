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

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int val) : _value(val << _fbits){}

Fixed::Fixed(const float val) : _value(roundf(val * (float)(1 << _fbits))){}

Fixed::~Fixed(){}

Fixed::Fixed(Fixed const & other){
	*this = other;
}

int		Fixed::getRawBits() const
{
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
	_value = other._value;
	return *this;
}
std::ostream & operator<<(std::ostream & o, Fixed const & rhs){
	o << rhs.toFloat();
	return o;
}

Fixed Fixed::operator+(Fixed const & other) const{

	return (Fixed( this->toFloat() + other.toFloat()));
}
Fixed Fixed::operator-(Fixed const & other) const{
	return (Fixed( this->toFloat() - other.toFloat()));
}
Fixed Fixed::operator*(Fixed const & other) const{
	float f = toFloat() * other.toFloat();
	return Fixed(f);
}
Fixed Fixed::operator/(Fixed const & other) const{
	float f = toFloat() / other.toFloat();
	return Fixed(f);
}

bool Fixed::operator==(Fixed const & other) const{
	return (_value == other.getRawBits());
}
bool Fixed::operator!=(Fixed const & other) const{
	return !(*this == other);
}
bool Fixed::operator>(Fixed const & other) const{
	return (_value > other.getRawBits());
}
bool Fixed::operator<(Fixed const & other) const{
	return (_value < other.getRawBits());
}
bool Fixed::operator>=(Fixed const & other) const {
	return !(*this < other);
}
bool Fixed::operator<=(Fixed const & other) const{
	return !(*this > other);
}

Fixed & Fixed::operator++(){
	_value++;
	return (*this);
}
Fixed Fixed::operator++(int){
	Fixed tmp(*this);
	++(*this);
	return tmp;
}
Fixed & Fixed::operator--(){
	_value--;
	return (*this);
}
Fixed Fixed::operator--(int){
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

Fixed &	Fixed::min(Fixed & a, Fixed & b){
	return (a < b ? a : b);
}
Fixed const &	Fixed::min(Fixed const & a, Fixed const & b){
	return (a < b ? a : b);
}
Fixed &	Fixed::max(Fixed & a, Fixed & b){
	return (a > b ? a : b);
}
Fixed const &	Fixed::max(Fixed const & a, Fixed const & b){
	return (a > b ? a : b);
}
