/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:23:56 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/10 19:40:39 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice Constructor called" << std::endl;
}

Ice::Ice(Ice const &copy) : AMateria("ice")
{
	std::cout << "Ice Copy Constructor called" << std::endl;
	(void)copy;
}

Ice::~Ice()
{
	std::cout << "Ice Destructor called" << std::endl;
}

Ice const &Ice::operator=(Ice const &copy)
{
	std::cout << "Ice Assignement Operator called" << std::endl;
	(void)copy;
	return *this;
}

AMateria *Ice::clone() const
{
	Ice *clone = new Ice(*this);
	return clone;
}

void Ice::use(ICharacter &target)
{	
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
