/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:48:00 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/07 12:03:01 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Constructor called" << std::endl;
	this->_HitPoint = 100;
	this->_EnergyPoint = 50;
	this->_AttackDamage = 20;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap born named " << this->_Name << std::endl;
	this->_HitPoint = 100;
	this->_EnergyPoint = 50;
	this->_AttackDamage = 20;
}
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}
ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called for " << this->_Name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	this->_Name = copy._Name;
	this->_HitPoint = copy._HitPoint;
	this->_EnergyPoint = copy._EnergyPoint;
	this->_AttackDamage = copy._AttackDamage;
	return *this;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap "<<  this->_Name <<" was entred in GateKeeper Mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_EnergyPoint && this->_HitPoint)
	{
		std::cout << "ScavTrap " << this->_Name << " attacks " << target << " causing " << this->_AttackDamage << " points of damage!." << std::endl;
		this->_EnergyPoint--;
	}
	else
	{
		std::cout << "ScavTrap " << this->_Name << " can't attacks, he don't have EnergyPoint or HitPoint." << std::endl;
	}
}