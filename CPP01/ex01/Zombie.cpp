/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:08:11 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/01 00:44:51 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Zombie born." << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << this->_name << " was born." << std::endl;
}
Zombie::~Zombie()
{
	std::cout << this->_name << " died." << std::endl;
}

void Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}