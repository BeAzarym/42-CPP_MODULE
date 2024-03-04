/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:06:40 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/04 19:44:23 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Constructor called" << std::endl;
	this->_FixedNum = 0;
}
Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy Constructor called" << std::endl;
	this->_FixedNum = f._FixedNum;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &f)
		this->_FixedNum = f._FixedNum;
	return *this;
}

int Fixed::getRawBits(void) const
{
	return this->_FixedNum;
}
void Fixed::setRawBit(int n)
{
	this->_FixedNum = n;
}
