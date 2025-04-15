/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:02:32 by cchabeau          #+#    #+#             */
/*   Updated: 2025/01/28 23:24:51 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <exception>

# define RED "\033[31m"
# define GREY "\033[90m"
# define BOLD_BLUE "\033[1;34m"
# define RESET "\033[0m"


class NotFoundException : public std::exception
{
	public:
		virtual const char * what() const throw()
		{
			return ("Value not found.");
		}
};

template <typename T>
void easyfind(T& container, int i)
{
	typename T::iterator it;

	it = find(container.begin(), container.end(), i);
	if (it == container.end())
		throw(NotFoundException());
	else
		std::cout << "Value was found." << std::endl;
}

#endif