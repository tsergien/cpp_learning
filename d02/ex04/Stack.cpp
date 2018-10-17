/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsergien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:37:46 by tsergien          #+#    #+#             */
/*   Updated: 2018/10/04 15:37:48 by tsergien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stack.hpp"

Stack::Stack(): _size(INIT_SIZE), _num(new Fixed[INIT_SIZE]), top_ind(0){}

Stack::~Stack(){
	delete [] _num;
}

void	Stack::push(int num)
{
	if (top_ind == _size -1)
	{
		_size += INIT_SIZE;
		Fixed *tmp = new Fixed[_size];
		for (int i = 0; i < _size - INIT_SIZE; i++)
			tmp[i] = _num[i];
		delete []  _num;
		_num = tmp;
	}
	
}

int		Stack::pop(){
	if (top_ind == 0)
		return 0;
	top_ind--;;
}

Fixed	Stack::peek()
{
	if (_size < 1)
		return 0;
	return _num[_size - 1];
}