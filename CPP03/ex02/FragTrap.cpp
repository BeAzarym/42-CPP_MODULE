/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:22:45 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/07 12:33:46 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "Constructor called" << std::endl;
	this->_HitPoint = 100;
	this->_EnergyPoint = 100;
	this->_AttackDamage = 30;
}
FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FragTrap born named " << this->_Name << std::endl;
	this->_HitPoint = 100;
	this->_EnergyPoint = 100;
	this->_AttackDamage = 30;
}
FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}
FragTrap::~FragTrap()
{
	std::cout << "Destructor called for FragTrap " << this->_Name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	std::cout << "Copy Assignement operator called" << std::endl;
	this->_Name = copy._Name;
	this->_HitPoint = copy._HitPoint;
	this->_EnergyPoint = copy._EnergyPoint;
	this->_AttackDamage = copy._AttackDamage;
	return *this;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_Name << " request a high fives !" << std::endl;
}