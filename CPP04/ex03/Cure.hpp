/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:29:17 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/10 19:43:13 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "Character.hpp"

class Cure : public AMateria
{
  public:
	Cure();
	Cure(Cure const &copy);
	~Cure();

	Cure const &operator=(Cure const &copy);

	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif
