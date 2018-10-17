/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 09:14:59 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/04 09:15:00 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

int main( void )
{
	Fixed aa;
	Fixed const bb( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << aa << std::endl;
	std::cout << ++aa << std::endl;
	std::cout << aa << std::endl;
	std::cout << aa++ << std::endl;
	std::cout << aa << std::endl;
	std::cout << bb << std::endl;
	
	std::cout << Fixed::max( aa, bb ) << std::endl;
	
	Fixed a(3);
	Fixed b(2.5f);
	std::cout << "a = " << a.toFloat() << "\n";
	std::cout << "b = " << b.toFloat() << "\n";
	Fixed c = a * b;
	std::cout << "a*b: " << c.toFloat() << std::endl;
	std::cout << "a: " << a.toFloat() << std::endl;
	c = a + b;
	std::cout << "a+b: " << c.toFloat() << std::endl;
	std::cout << "a: " << a.toFloat() << std::endl;
	c = a - b;
	std::cout << "a-b: " << c.toFloat() << std::endl;
	c = a / b;
	std::cout << "a/b: " << c.toFloat() << std::endl;
	b = 0;
	c = a / b;
	std::cout << "a/:0 " << c.toFloat() << std::endl;

	b = (float)3.01;
	bool d;
	d = a > b;
	std::cout << "\n>: " << d << std::endl;
	d = a < b;
	std::cout << "a<b: " << d << std::endl;
	d = a >= b;
	std::cout << "a>=b: " << d << std::endl;
	d = a <= b;
	std::cout << "a<=b: " << d << std::endl;
	d = a == b;
	std::cout << "a==b: " << d << std::endl;
	d = a != b;
	std::cout << "a!=b " << d << std::endl;


	return 0;
}
