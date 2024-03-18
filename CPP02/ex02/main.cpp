/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:42:03 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/18 20:14:58 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a(5);
	Fixed b(10);
	Fixed c(9.9999f);
	Fixed d(42);

	//
	//				OPERATOR
	//
	std::cout << "[TEST] OPERATOR" << std::endl;
	std::cout << "a (" << a << ") + b (" << b << ") = " << a + b << std::endl;
	std::cout << "a (" << b << ") - d (" << d << ") = " << b - d << std::endl;
	std::cout << "a (" << c << ") * d (" << d << ") = " << c * d << std::endl;
	std::cout << "a (" << a << ") / b (" << b << ") = " << a / b << std::endl;
	//
	//				COMPARATOR
	//
	std::cout << "[TEST] COMPARATOR" << std::endl;
	if (a < b)
		std::cout << "a (" << a << ") is lower than b (" << b << ")" << std::endl;
	else
		std::cout << "a (" << a << ") is not lower than b (" << b << ")" << std::endl;

	if (a > d)
		std::cout << "a (" << a << ") is higher than d (" << d << ")" << std::endl;
	else
		std::cout << "a (" << a << ") is not higher than d (" << d << ")" << std::endl;

	if (c == a)
		std::cout << "c (" << c << ") is equal to a (" << a << ")" << std::endl;
	else
		std::cout << "c (" << c << ") is not equal to a (" << a << ")" << std::endl;

	if (d >= b)
		std::cout << "d (" << d << ") is higher or equal to b (" << b << ")" << std::endl;
	else
		std::cout << "d (" << d << ") is not higher or equal to b (" << b << ")" << std::endl;

	if (a <= d)
		std::cout << "a (" << a << ") is lower or equal to d (" << d << ")" << std::endl;
	else
		std::cout << "a (" << a << ") is not lower or equal to d (" << d << ")" << std::endl;

	if (d != c)
		std::cout << "d (" << d << ") is different to (" << c << ")" << std::endl;
	else
		std::cout << "d (" << d << ") is not different to (" << c << ")" << std::endl;

	//
	//				INCREMENT
	//
	std::cout << "[TEST] INCREMENT" << std::endl;
	std::cout << "a: " << a.getRawBits() << std::endl;
	std::cout << "PRE-INCREMENT " << ++a << std::endl;
	std::cout << "a: " << a.getRawBits() << std::endl;
	std::cout << "POST-INCREMENT " << a++ << std::endl;
	std::cout << "a: " << a.getRawBits() << std::endl;
	std::cout << "PRE-DECREMENT " << --a << std::endl;
	std::cout << "a: " << a.getRawBits() << std::endl;
	std::cout << "POST-DECREMENT " << a-- << std::endl;
	std::cout << "a: " << a.getRawBits() << std::endl;

	//
	//		MIN MAX
	//
	std::cout << "[TEST] MIN MAX FUNC" << std::endl;
	std::cout << "MiN a (" << a << ") and b (" << b << ") :" << Fixed::min(a, b) << std::endl;
	std::cout << "MAX a (" << a << ") and d (" << d << ") :" << Fixed::max(a, d) << std::endl;
	return (0);
}