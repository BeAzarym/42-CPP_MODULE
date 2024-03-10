/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:18:10 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/07 20:23:46 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: _type("Default")
{
	std::cout << "WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal Assignement Operator called" << std::endl;
	this->_type = copy._type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "**WRONG STRANGE NOISE**" << std::endl;
}
