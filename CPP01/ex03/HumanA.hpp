/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:04:13 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/01 15:59:17 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class HumanA
{
  private:
	std::string _name;
	Weapon &_weapon;

  public:
	  HumanA(std::string name, Weapon &weapon);
	  ~HumanA();

	  void attack() const;
};

#endif