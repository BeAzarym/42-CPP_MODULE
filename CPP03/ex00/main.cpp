/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 21:40:18 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/06 22:06:20 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap Paul("Paul");
	ClapTrap Pierre("Pierre");

	Paul.setAttackDamage(1);
	Paul.attack("Pierre");
	Pierre.takeDamage(Paul.getAttackDamage());
	Pierre.beRepaired(1);
	Pierre.attack("Paul");
	Paul.takeDamage(Pierre.getAttackDamage());
}