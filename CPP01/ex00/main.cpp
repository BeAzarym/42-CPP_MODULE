/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:07:04 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/01 00:34:25 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
	Zombie *Bob = newZombie("Bob");
	Zombie *Kevin = newZombie("Kevin");

	Bob->announce();
	Kevin->announce();
	randomChump("Pelo");

	delete Bob;
	delete Kevin;
	return 0;
}