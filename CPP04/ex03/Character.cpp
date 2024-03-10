/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:12:31 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/10 19:54:06 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name("Bob")
{
	std::cout << "Character Constructor called for " << this->_name << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name): _name(name)
{
	std::cout << "Character Constructor called for " << name << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character &copy)
{
	std::cout << "Character Copy Constructor called" << std::endl;
	*this = copy;
}

Character::~Character()
{
	std::cout << "Character Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

const Character &Character::operator=(const Character &copy)
{
	std::cout << "Character Assignement Operator called" << std::endl;
	this->_name = copy._name;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = copy._inventory[i]->clone();
	}
	return (*this);
}

const std::string &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = materia;
			return ;
		}
	}
	std::cout << "Failled to equip Materia, inventory full." << std::endl;
}

void Character::unequip(int index)
{
	if (index <= 0 && index >= 3 && this->_inventory[index])
	{
		std::cout << "You drop the materia " << this->_inventory[index]->getType() << std::endl;
		this->_inventory[index] = NULL;
		return ;
	}
	std::cout << "Failled to drop Materia,Bad index or there is no Materia in inventory " << std::endl;
}

void Character::use(int index, ICharacter &target)
{
	if (index >= 0 && index <= 3 && this->_inventory[index])
	{
		this->_inventory[index]->use(target);
		return;
	}
	else
	{
		std::cout << "Failled to use Materia" << std::endl;
	}
}
