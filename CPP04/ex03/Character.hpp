/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:04:41 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/10 19:50:05 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
  private:
	std::string _name;
	AMateria *_inventory[4];

  public:
	Character();
	Character(std::string name);
	Character(const Character &copy);
	~Character();

	const Character &operator=(const Character &copy);

	virtual const std::string &getName() const;
	virtual void equip(AMateria *materia);
	virtual void unequip(int index);
	virtual void use(int index, ICharacter &target);
};
#endif