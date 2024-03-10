/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:55:28 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/10 17:40:31 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): AAnimal()
{
	std::cout << "Dog Constructor called" << std::endl;
	this->_type = "Dog";
	this->_Brain = new Brain();
}

Dog::Dog(const Dog &copy): AAnimal(copy)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	this->_type = copy._type;
	this->_Brain = new Brain(*(copy._Brain));
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete this->_Brain;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "Dog Assignement Operator called" << std::endl;
	this->_type = copy._type;
	this->_Brain = copy._Brain;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "**Wouf Wouf**" << std::endl;
}

Brain *Dog::getBrain() const
{
	return (this->_Brain);
}
