/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:37:55 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/04 15:37:57 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP
#include "Fixed.class.cpp"
#define INIT_SIZE 50
class Stack
{
	Fixed*	_num;
	unsigned _size;
	unsigned top_ind;
public:
	Stack();
	~Stack();
	void	push(float num);
	int		pop();
	Fixed	peek();
};

#endif
