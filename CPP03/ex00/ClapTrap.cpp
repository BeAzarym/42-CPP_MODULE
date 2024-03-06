/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:48:39 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/06 22:05:48 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _Name("Bob"), _HitPoint(10), _EnergyPoint(10), _AttackDamage(0)
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _Name(name), _HitPoint(10), _EnergyPoint(10), _AttackDamage(0)
{
	std::cout << "People born named " << this->getName() << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Copy Assignement operator called" << std::endl;
	this->_Name = copy._Name;
	this->_EnergyPoint = copy._EnergyPoint;
	this->_HitPoint = copy._HitPoint;
	this->_AttackDamage = copy._AttackDamage;
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called for " << this->getName() << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_EnergyPoint && this->_HitPoint)
	{
		std::cout << "ClapTrap " << this->_Name << " attacks " << target << " causing " << this->_AttackDamage << " AttackDamage." << std::endl;
		this->_EnergyPoint--;
	}
	else
	{
		std::cout << "ClapTrap " << this->_Name << " can't attacks,he only have " << this->_EnergyPoint << " EnergyPoint." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_Name << " was attacked, he looses " << amount << " HitPoint." << std::endl;
	this->_HitPoint -= amount;
	std::cout << "He have now " << this->_HitPoint << " HitPoint." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_EnergyPoint && this->_HitPoint < 10)
	{
		this->_HitPoint += amount;
		std::cout << "ClapTrap " << this->_Name << " repair himself, healing " << amount << " HitPoint.";
		std::cout << std::endl << "He have now " << this->_HitPoint << " HitPoint." << std::endl;
		this->_EnergyPoint--;
	}
	else if (this->_EnergyPoint && this->_HitPoint > 10)
	{
		std::cout << "ClapTrap " << this->_Name << " can't heal himself anymore." << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_Name << " can't heal,he only have " << this->_EnergyPoint << " EnergyPoint." << std::endl;
	}
}

unsigned int ClapTrap::getHitPoint()
{
	return (this->_HitPoint);
}

unsigned int ClapTrap::getEnergyPoint()
{
	return (this->_EnergyPoint);
}

unsigned int ClapTrap::getAttackDamage()
{
	return (this->_AttackDamage);
}

std::string ClapTrap::getName()
{
	return (this->_Name);
}

void ClapTrap::setAttackDamage(unsigned int amount)
{
	this->_AttackDamage = amount;
}
