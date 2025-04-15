/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:35:31 by cchabeau          #+#    #+#             */
/*   Updated: 2025/04/15 12:42:53 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char**argv)
{
	if (argc != 2)
	{
		std::cerr << "[ERROR] ./btc <file input>" << std::endl;
		return (1);
	}
	BitcoinExchange btc;
	btc.computeValue(argv[1]);
	return (0);
}