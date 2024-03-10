/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:41:58 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/10 17:38:55 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() :_type("Default")
{
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "AAnimal Copy constructor called" << std::endl;
	*this = copy;
}

 AAnimal::~AAnimal() 
{
	std::cout << "AAnimal Destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &copy)
{
	std::cout << "AAnimal Assignement Operator called" << std::endl;
	this->_type = copy._type;
	return *this;
}

std::string AAnimal::getType() const
{
	return this->_type;
}

