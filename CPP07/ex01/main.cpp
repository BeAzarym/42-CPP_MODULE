/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:21:01 by cchabeau          #+#    #+#             */
/*   Updated: 2025/01/28 18:32:11 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RED "\033[31m"
# define GREY "\033[90m"
# define BOLD_BLUE "\033[1;34m"
# define RESET "\033[0m"

#include "iter.hpp"
#include <iostream>
#include <string>

void incr(int &x)
{
	x++;
}

void decr(int &x)
{
	x--;
}

int main(void)
{
	std::cout << BOLD_BLUE << "Incrementing each element of an array" << RESET << std::endl;
	
	int number[] = {0, 1, 2, 3, 4, 5};

	iter<int>(number, static_cast<size_t>(6), incr);
	for (int i = 0; i < 6; i++)
	{
		std::cout << number[i] << std::endl;
	}

	std::cout << std::endl;

	std::cout << BOLD_BLUE << "Decrementing each element of an array" << RESET << std::endl;

	iter<int>(number, static_cast<size_t>(6), decr);
	for (int i = 0; i < 6; i++)
	{
		std::cout << number[i] << std::endl;
	}
}