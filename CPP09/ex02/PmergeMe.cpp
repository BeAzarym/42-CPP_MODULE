/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:11:11 by cchabeau          #+#    #+#             */
/*   Updated: 2025/04/17 12:01:04 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void parseInput(char **argv, std::vector<int> &int_vector, std::list<int> &int_list)
{
	for (size_t i = 1; argv[i] != NULL; i++)
	{
		int res = std::atoi(argv[i]);
		if ((res == 0 && !isdigit(*argv[i])) || res < 0)
			throw NotANumber();

		std::vector<int>::iterator it = std::find(int_vector.begin(), int_vector.end(), res);
		if (it != int_vector.end())
			throw NumberDuplicate();
		
		int_vector.push_back(res);
		int_list.push_back(res);
	}	
}

const char *NotANumber::what() const throw()
{
	return ("Error: Invalid input, must be a positive number.");
}

const char *NumberDuplicate::what() const throw()
{
	return ("Error: Duplicate Number in stack.");
}