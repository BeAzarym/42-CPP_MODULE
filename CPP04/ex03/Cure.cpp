/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:23:56 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/22 20:46:16 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure Constructor called" << std::endl;
}

Cure::Cure(Cure const &copy) : AMateria("cure")
{
	std::cout << "Cure Copy Constructor called" << std::endl;
	(void)copy;
}

Cure::~Cure()
{
	std::cout << "Cure Destructor called" << std::endl;
}

Cure const &Cure::operator=(Cure const &copy)
{
	std::cout << "Cure Assignement Operator called" << std::endl;
	(void)copy;
	return *this;
}

AMateria *Cure::clone() const
{
	Cure *clone = new Cure(*this);
	return clone;
}

void Cure::use(ICharacter &target)
{	
	std::cout << "* heals " << target.getName() << " 's wound *" << std::endl;
}
