/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:06:40 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/04 21:33:47 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Constructor called" << std::endl;
	this->_FixedNum = 0;
}
Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed(const float n)
{
	std::cout << "Constructor float called " << std::endl;
	this->_FixedNum = roundf(n * (1 << this->fractionnal_bit));
}
Fixed::Fixed(const int n)
{
	std::cout << "Constructor int called" << std::endl;
	this->_FixedNum = n << this->fractionnal_bit;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &f)
		this->_FixedNum = f._FixedNum;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->_FixedNum);
}
void Fixed::setRawBit(int n)
{
	this->_FixedNum = n;
}

float Fixed::toFloat(void) const
{
	return (float)this->_FixedNum / (1 << this->fractionnal_bit);
}

int Fixed::toInt(void) const
{
	return this->_FixedNum >> this->fractionnal_bit;
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
