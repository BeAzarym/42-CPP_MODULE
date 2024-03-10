/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:42:24 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/10 19:46:27 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const &copy): IMateriaSource(copy)
{
	std::cout << "MateriaSource Copy Constructor called" << std::endl;
	*this = copy;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

const MateriaSource &MateriaSource::operator=(MateriaSource const &copy)
{
	std::cout << "MateriaSource Assignement Operator called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = copy._inventory[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *Materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = Materia;
			return ;
		}
	}
	std::cout << "Failled to learn Materia" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	AMateria	*clone;

	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] && (this->_inventory[i]->getType() == type))
		{
			clone = this->_inventory[i]->clone();
			return (clone);
		}
	}
	std::cout << "Failled to create Materia" << std::endl;
	return (NULL);
}
