/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:31:26 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/01 15:36:28 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>


class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon;
		
		public:
			HumanB(std::string name);
			~HumanB();

			void attack();
			void setWeapon(Weapon &weapon);
};

#endif