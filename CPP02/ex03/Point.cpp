/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:48:59 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/05 19:12:57 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _X(0), _Y(0)
{
}

Point::Point(Point &cpy)
{
	this->_X = cpy.getX();
	this->_Y = cpy.getY();
}

Point::Point(float x, float y)
{
	this->_X = x;
	this->_Y = y;
}

Point::~Point()
{
}

Point &Point::operator=(Point &cpy)
{
	if (this != &cpy)
	{
		this->_X = cpy.getX();
		this->_Y = cpy.getY();
	}
	return (*this);
}

Fixed Point::getX()
{
	return (this->_X);
}

Fixed Point::getY()
{
	return (this->_Y);
}
