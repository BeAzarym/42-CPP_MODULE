/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:43:06 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/07 13:15:26 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
	std::cout << "Constructor called" << std::endl;
	ClapTrap::_Name = "Bob_clap_name";
	this->_Name = "Bob";
	this->_HitPoint = 100;
	this->_EnergyPoint = 50;
	this->_AttackDamage = 50;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap born named" << name << std::endl;
	this->_Name = name;
	this->_HitPoint = 100;
	this->_EnergyPoint = 50;
	this->_AttackDamage = 50;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy),  FragTrap(copy), ScavTrap(copy)
{
	std::cout << "Diamond Trap copy constructor called" << std::endl;
	*this = copy;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor called for DiamondTrap " << this->_Name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
	this->_Name = copy._Name;
	this->_HitPoint = copy._HitPoint;
	this->_EnergyPoint = copy._EnergyPoint;
	this->_AttackDamage = copy._AttackDamage;
	return *this;
}

void DiamondTrap::whoAmI()
{
	std::cout << "My ClapTrap name is " << ClapTrap::_Name << " but my DiamondTrap name is " << this->_Name << std::endl;
}
