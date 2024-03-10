/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:47:47 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/10 19:39:08 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

class ICharacter;

class AMateria
{
  protected:
	std::string _type;

  public:
	  AMateria();
	  AMateria(std::string const &type);
	  AMateria(const AMateria &copy);
	  virtual ~AMateria();

	  const AMateria &operator=(const AMateria &copy);

	  std::string const &getType() const; // Returns the materia type
	  virtual AMateria *clone() const = 0;
	  virtual void use(ICharacter &target);
};

#endif