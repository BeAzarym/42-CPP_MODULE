/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:49:08 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/05 17:51:14 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
	private:
		Fixed _X;
		Fixed _Y;

	public:
		Point();
		Point(Point &cpy);
		Point(float x, float y);
		~Point();

		Point &operator=(Point &cpy);

		Fixed getX();
		Fixed getY();
};

#endif