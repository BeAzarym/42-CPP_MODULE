/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:40:18 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/07 13:11:59 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	ClapTrap Paul("Paul");
	ClapTrap Pierre("Pierre");
	ScavTrap Jean("Jean");
	FragTrap Jacque("Jacque");
	DiamondTrap Yve("Yve");

	Paul.setAttackDamage(1);
	Paul.attack("Pierre");
	Pierre.takeDamage(Paul.getAttackDamage());
	Pierre.beRepaired(1);
	Pierre.attack("Paul");
	Paul.takeDamage(Pierre.getAttackDamage());
	Jean.guardGate();
	Jean.attack("Pierre");
	Pierre.takeDamage(Jean.getAttackDamage());
	Pierre.beRepaired(10);
	Jacque.highFivesGuys();
	Yve.whoAmI();
	Yve.highFivesGuys();
	Yve.guardGate();
}