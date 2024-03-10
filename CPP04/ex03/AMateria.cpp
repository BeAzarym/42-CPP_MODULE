/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:53:30 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/10 18:02:31 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria Constructor called " << std::endl;
	return;
}

AMateria::AMateria(std::string const &type) :_type(type)
{
	std::cout << "AMateria Constructor called with type: "  << type << std::endl;
	return;
}

AMateria::AMateria(const AMateria &copy) : _type(copy._type)
{
	std::cout << "AMateria Copy constructor called" << std::endl;
	
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor called" << std::endl;
}

const AMateria &AMateria::operator=(const AMateria &copy)
{
	std::cout << "AMateria Assignement operator called" << std::endl;
	this->_type = copy._type;
	return *this;
}

std::string const & AMateria::getType() const
{
	return this->_type;
} 

void AMateria::use(ICharacter &target)
{
	(void)target;
	std::cout << "IF YOU CAN READ ME, THIS IS WEIRD" << std::endl;
}
