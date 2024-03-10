/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:49:33 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/10 17:09:10 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat Constructor called" << std::endl;
	this->_type = "Cat";
	this->_Brain = new Brain();
}
Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->_type = copy._type;
	this->_Brain = new Brain(*(copy._Brain));
}
Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete this->_Brain;
}
Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "Cat Assignement Operator called" << std::endl;
	this->_type = copy._type;
	this->_Brain = copy._Brain;
	return *this;
}
void Cat::makeSound() const
{
	std::cout << "**Meow Meow**" << std::endl;
}

Brain *Cat::getBrain() const
{
	return (this->_Brain);
}
