/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:07:04 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/14 12:11:40 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int n, std::string name);

int main(void)
{
	Zombie *Horde = zombieHorde(7, "Pierre");

	for (int i = 0; i < 7; i++)
		Horde[i].announce();

	delete[] Horde;
	return (0);
}