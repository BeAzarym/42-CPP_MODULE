/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:33:45 by cchabeau          #+#    #+#             */
/*   Updated: 2025/01/28 13:42:37 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << GREY << "Serializer Default constructor called" << RESET << std::endl;
}

Serializer::Serializer(const Serializer &copy)
{
	std::cout << GREY << "Serializer Copy constructor called" << RESET << std::endl;
	*this = copy;
	return ;
}

Serializer::~Serializer()
{
	std::cout << GREY << "Serializer Destructor called" << RESET << std::endl;
}

Serializer &Serializer::operator=(const Serializer &copy)
{
	std::cout << GREY << "Serializer assignement operator construcotr called" << RESET << std::endl;
	(void)copy;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}