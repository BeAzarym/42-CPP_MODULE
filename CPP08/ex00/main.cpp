/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:03:02 by cchabeau          #+#    #+#             */
/*   Updated: 2025/01/28 23:26:28 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
# define RED "\033[31m"
# define GREY "\033[90m"
# define BOLD_BLUE "\033[1;34m"
# define RESET "\033[0m"



int main(void)
{
	std::cout << BOLD_BLUE << "Vector test" << RESET << std::endl;
	std::vector<int> vector;
	for (int i = 0; i < 15; i++)
	{
		vector.push_back(i);
	}

	try
	{
		easyfind(vector, 10);
		easyfind(vector, -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
	std::cout << BOLD_BLUE << "Deque test" << RESET << std::endl;
	std::deque<int> deque;
	for (int i = 0; i < 25; i++)
	{
		deque.push_back(i);
	}

	try
	{
		easyfind(deque, 10);
		easyfind(deque, -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RED << std::endl;
	}

}