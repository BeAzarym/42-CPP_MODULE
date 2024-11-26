/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:42:18 by cchabeau          #+#    #+#             */
/*   Updated: 2024/11/26 21:05:49 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED << "Bad count of argument, must be used like ./convert arg" << RESET << std::endl;
		return (1);
	}
	if (argv[1] != NULL)
		ScalarConverter::convert(argv[1]);
	else
	{
		std::cout << RED << "ARGV is NULL" << RESET << std::endl;
		return (1);
	}
	return (0);
}
