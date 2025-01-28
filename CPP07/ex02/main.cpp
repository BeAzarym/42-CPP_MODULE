/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:40:28 by cchabeau          #+#    #+#             */
/*   Updated: 2025/01/28 21:39:29 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>


int main(void)
{
	std::cout << std::endl << BOLD_BLUE << "Array of Number test" << RESET << std::endl;
	Array<int> arrayNumber(10);
	for (unsigned int i = 0; i < arrayNumber.size(); i++)
	{
		std::cout << "Array[" << i << "] -> [" << arrayNumber[i] << "]" << std::endl;
	}
	std::cout << std::endl;
	for (unsigned int i = 0; i < arrayNumber.size(); i++)
	{
		arrayNumber[i] = i;
	}
	for (unsigned int i = 0; i < arrayNumber.size(); i++)
	{
		std::cout << "Array[" << i << "] -> [" << arrayNumber[i] << "]" << std::endl;
	}
	
	
	std::cout << std::endl;

	std::cout << std::endl << BOLD_BLUE << "Array of String test" << RESET << std::endl;
	Array<std::string> arrayString(7);
	for (unsigned int i = 0; i < arrayString.size(); i++)
	{
		std::cout << "Array[" << i << "] -> [" << arrayString[i] << "]" << std::endl;
	}
	std::cout << std::endl;
	
	for (unsigned int i = 0; i < arrayString.size(); i++)
	{
		arrayString[i].append("Hello");
	}
	for (unsigned int i = 0; i < arrayString.size(); i++)
	{
		std::cout << "Array[" << i << "] -> [" << arrayString[i] << "]" << std::endl;
	}
	std::cout << std::endl;
	
	
	try
	{
		std::cout << arrayString[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << arrayNumber[15] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}