/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:41:58 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/07 20:10:46 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() :_type("Default")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = copy;
}

 Animal::~Animal() 
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &copy)
{
	std::cout << "Animal Assignement Operator called" << std::endl;
	this->_type = copy._type;
	return *this;
}

std::string Animal::getType() const
{
	return this->_type;
}

void Animal::makeSound() const
{
	std::cout << "** MAKE RANDOM STRANGE NOISE**" << std::endl;
}
