/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:31:31 by cchabeau          #+#    #+#             */
/*   Updated: 2025/01/28 21:34:10 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

# define RED "\033[31m"
# define GREY "\033[90m"
# define BOLD_BLUE "\033[1;34m"
# define RESET "\033[0m"


template <typename T>
Array<T>::Array() : _array(new T(0)), _size(0)
{
	std::cout << GREY << "Default Constructor called." << RESET << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
	std::cout << GREY << "Assignement Constructor called." << RESET << std::endl;
}

template <typename T>
Array<T>::Array(Array const &copy)
{
	std::cout << GREY << "Copy Constructor called." << RESET << std::endl;
	*this = copy;
}

template <typename T>
Array<T>::~Array(void)
{
	std::cout << GREY << "Destructor called." << RESET << std::endl;
	delete[] this->_array;
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T> const &copy)
{
	std::cout << GREY << "Assignement operator Constructor called." << RESET << std::endl;
	
	if (this == &copy)
		return (*this);
	
	this->_size = copy._size;
	this->_array = new T(this->_size);
	
	for (int i = 0; i < this->_size; i++)
	{
		this->_array[i] = copy._array[i];
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int n)
{
	if (n >= this->_size)
		throw std::exception();
	return (this->_array[n]);
}

template <typename T>
unsigned int Array<T>::size(void)
{
	return (this->_size);
}
