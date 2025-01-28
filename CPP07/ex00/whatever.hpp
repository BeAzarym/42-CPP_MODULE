/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:54:10 by cchabeau          #+#    #+#             */
/*   Updated: 2025/01/28 18:11:14 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap( T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}

template <typename T>
T min( T const &a, T const &b)
{
	return (a < b ? a : b);
}

template <typename T>
T max (T const &a, T const &b)
{
	return (a > b ? a : b);
}

#endif