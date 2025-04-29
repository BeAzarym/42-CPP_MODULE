/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:41:18 by cchabeau          #+#    #+#             */
/*   Updated: 2025/04/29 13:37:50 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int RPN(std::string &str)
{
	std::stack<int> stack;
	int res = 0;
	if (str.empty())
	{
		std::cerr << "Error: Input is empty." << std::endl;
		return -1;
	}
	for (size_t i = 0; i != str.size(); i++)
	{
		if (isdigit(str[i]))
			stack.push(static_cast<int>(str[i] - 48));
		else if (str[i] == ' ')
			continue;
		else
		{
			if (stack.size() < 2)
			{
				std::cerr << "Error: Stack is invalid" << std::endl;
				return -1;
			}
			if (str[i] == '+')
			{
				res = stack.top();
				stack.pop();
				stack.top() += res;
			}
			else if (str[i] == '-')
			{
				res = stack.top();
				stack.pop();
				stack.top() -= res;
			}
			else if (str[i] == '*')
			{
				res = stack.top();
				stack.pop();
				stack.top() *= res;
			}
			else if (str[i] == '/')
			{
				res = stack.top();
				if (res == 0)
				{
					std::cerr << "Error: Can't divide by 0." << std::endl;
					return -1;
				}
				stack.pop();
				stack.top() /= res;
			}
			else
			{
				std::cerr << "Error: Invalide operation." << std::endl;
				return -1;
			}
		}
	}
	if (stack.size() > 1)
	{
		std::cerr << "Error: Invalide computation" << std::endl;
		return -1;
	}
	std::cout << stack.top() << std::endl;
	return 0;
}