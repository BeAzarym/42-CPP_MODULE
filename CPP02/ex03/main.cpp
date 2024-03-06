/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:42:03 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/06 20:38:02 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point A, Point B, Point C, Point X);

int	main(void)
{
	Point a(5.5, 3.5);
	Point b(-5.0, 0);
	Point c(0, 5);
	Point x(-2, 2);
	Point y(10, 2);

	std::cout << "a: ("  << a.getX() << "," << a.getY() << std::endl;
	std::cout << "b: " << b.getX() << "," << b.getY() << std::endl;
	std::cout << "c: " << c.getX() << "," << c.getY() << std::endl;

	std::cout << "Point x " << bsp(a, b, c, x) << std::endl;
	std::cout << "Point y " << bsp(a, b, c, y) << std::endl;
}