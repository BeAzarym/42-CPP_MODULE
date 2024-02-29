/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:38:08 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/01 00:45:01 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *Horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		Horde[i].setName(name);
	return Horde;
}
