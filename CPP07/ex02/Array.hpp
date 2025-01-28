/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:40:11 by cchabeau          #+#    #+#             */
/*   Updated: 2025/01/28 21:31:22 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>
#include <string>


template<typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;
	
	public:
		Array(void);
		Array(unsigned int n);
		~Array();
		Array(const Array<T> &copy);
		Array<T> &operator=(const Array<T> &copy);

		unsigned int size(void);
		T &operator[](unsigned int x);
};

#include "Array.tpp"
#endif