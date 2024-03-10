/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:26:34 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/07 20:36:22 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	std::cout << "WrongCat Assignement Operator called" << std::endl;
	this->_type = copy._type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "**Meow Meow**" << std::endl;
}
