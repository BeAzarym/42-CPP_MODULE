/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:42:03 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/18 20:26:50 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point A, Point B, Point C, Point X);

int	main(void)
{
	Point a(0, 8);
	Point b(-8, 0);
	Point c(8, 0);
	Point x(-2, 2);
	Point y(10, 2);
	Point z(0, 7);

	std::cout << "a: (" << a.getX() << "),(" << a.getY() << ")" << std::endl;
	std::cout << "b: (" << b.getX() << "),(" << b.getY() << ")" << std::endl;
	std::cout << "c: (" << c.getX() << "),(" << c.getY() << ")" << std::endl;

	std::cout << "x in abc: " << bsp(a, b, c, x) << std::endl;
	std::cout << "y in abc: " << bsp(a, b, c, y) << std::endl;
	std::cout << "z in abc: " << bsp(a, b, c, z) << std::endl;
}