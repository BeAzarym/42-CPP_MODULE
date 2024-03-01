/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:37:24 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/01 15:59:54 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
}
HumanB::~HumanB()
{
}

void HumanB::attack()
{
	if (this->_weapon)
		std::cout << this->_name << "attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << "attacks with no weapon" << std::endl;
}
void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}