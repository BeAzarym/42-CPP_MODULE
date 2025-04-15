/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:41:32 by cchabeau          #+#    #+#             */
/*   Updated: 2025/04/10 13:29:20 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::vector<int> randomVector;

	
	Span numbers = Span(10);
	numbers.fillRandomBuffer(0, 20000);
	numbers.printBuffer();
	std::cout << numbers.shortestSpan() << std::endl;
	std::cout << numbers.longestSpan() << std::endl;

	sp.printBuffer();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	return 0;
}