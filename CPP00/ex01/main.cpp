/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:05:24 by cchabeau          #+#    #+#             */
/*   Updated: 2024/02/29 15:33:19 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook PhoneBook;
	std::string str;

	std::cout << "Command are ADD, SEARCH or EXIT" << std::endl;

	while (1)
	{
		std::cout << "$>";
		if (!std::getline(std::cin, str))
			return (-1);
		if (!str.compare("ADD"))
			PhoneBook.add();
		else if (!str.compare("SEARCH"))
			PhoneBook.search();
		else if (!str.compare("EXIT"))
			break;
		else
			std::cout << "Command are ADD, SEARCH or EXIT" << std::endl;
	}
}
