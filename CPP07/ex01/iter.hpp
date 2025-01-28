/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:17:57 by cchabeau          #+#    #+#             */
/*   Updated: 2025/01/28 18:32:25 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <cstdlib>

template <typename T>
void iter(T* ptr, size_t n, void (*func)(T&))
{
	for (size_t i = 0; i < n; i++)
	{
		func(ptr[i]);
	}
}

#endif