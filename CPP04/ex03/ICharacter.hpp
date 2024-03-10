/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:51:47 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/10 18:03:12 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <string>

class AMateria;

class ICharacter
{
  public:
	  virtual ~ICharacter() {}
	  virtual std::string const &getName() const = 0;
	  virtual void equip(AMateria *m) = 0;
	  virtual void unequip(int idx) = 0;
	  virtual void use(int idx, ICharacter &target) = 0;
};

#endif