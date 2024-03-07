/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:49:33 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/07 20:11:21 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat Constructor called" << std::endl;
	this->_type = "Cat";
}
Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = copy;
}
Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}
Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "Cat Assignement Operator called" << std::endl;
	this->_type = copy._type;
	return *this;
}
void Cat::makeSound() const
{
	std::cout << "**Meow Meow**" << std::endl;
}
