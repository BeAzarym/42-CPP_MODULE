/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:06:40 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/18 20:16:24 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	// std::cout << "Constructor called" << std::endl;
	this->_FixedNum = 0;
}
Fixed::Fixed(const Fixed &f)
{
	// std::cout << "Copy Constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed(const float n)
{
	// std::cout << "Constructor float called " << std::endl;
	this->_FixedNum = roundf(n * (1 << this->fractionnal_bit));
}
Fixed::Fixed(const int n)
{
	// std::cout << "Constructor int called" << std::endl;
	this->_FixedNum = n << this->fractionnal_bit;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	// std::cout << "Copy assignement operator called" << std::endl;
	if (this != &f)
		this->_FixedNum = f._FixedNum;
	return (*this);
}

bool Fixed::operator>(const Fixed &f) const
{
	return (this->getRawBits() > f.getRawBits());
}
bool Fixed::operator<(const Fixed &f) const
{
	return (this->getRawBits() < f.getRawBits());
}
bool Fixed::operator>=(const Fixed &f) const
{
	return (this->getRawBits() >= f.getRawBits());
}
bool Fixed::operator<=(const Fixed &f) const
{
	return (this->getRawBits() <= f.getRawBits());
}
bool Fixed::operator==(const Fixed &f) const
{
	return (this->getRawBits() == f.getRawBits());
}
bool Fixed::operator!=(const Fixed &f) const
{
	return (this->getRawBits() != f.getRawBits());
}

Fixed Fixed::operator+(const Fixed &f) const
{
	Fixed x;

	x.setRawBit(this->getRawBits() + f.getRawBits());
	return (x);
}
Fixed Fixed::operator-(const Fixed &f) const
{
	Fixed x;

	x.setRawBit(this->getRawBits() - f.getRawBits());
	return (x);
}
Fixed Fixed::operator*(const Fixed &f) const
{
	Fixed x;

	x = this->toFloat() * f.toFloat();
	return (x);
}
Fixed Fixed::operator/(const Fixed &f) const
{
	Fixed x;

	x = this->toFloat() / f.toFloat();
	return (x);
}

Fixed Fixed::operator++(int)
{
	this->_FixedNum++;
	return (*this);
}

Fixed &Fixed::operator++()
{
	this->_FixedNum += 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	this->_FixedNum-= 1;
	return (*this);
}
Fixed &Fixed::operator--(void)
{
	this->_FixedNum--;
	return (*this);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed const &Fixed::min(Fixed const &f1, Fixed const &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}
Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}
Fixed const &Fixed::max(Fixed const &f1, Fixed const &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
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
	return (this->_FixedNum >> this->fractionnal_bit);
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}