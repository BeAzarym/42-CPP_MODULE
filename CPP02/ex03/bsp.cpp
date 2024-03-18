/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:02:05 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/18 20:24:39 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Fixed	calculationTriangleArea(Point A, Point B, Point C)
{
	Fixed	Area;

	Area = (A.getX() * (B.getY() - C.getY()) + B.getX() * (C.getY() - A.getY()) + C.getX() * (A.getY() - B.getY()));
	if (Area < 0)
		return (Area * (-1));
	return (Area);
}

bool	bsp(Point A, Point B, Point C, Point X)
{
	Fixed TotalArea(calculationTriangleArea(A, B, C));
	Fixed Surface1(calculationTriangleArea(A, B, X));
	Fixed Surface2(calculationTriangleArea(B, C, X));
	Fixed Surface3(calculationTriangleArea(A, C, X));

	if (Surface1 == 0 || Surface2 == 0 || Surface3 == 0)
		return (false);
	return (TotalArea == (Surface1 + Surface2 + Surface3));
}