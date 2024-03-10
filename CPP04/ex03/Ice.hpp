/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:02:19 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/10 19:43:22 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "Character.hpp"

class Ice : public AMateria
{
  public:
	Ice();
	Ice(Ice const &copy);
	~Ice();
	Ice const &operator=(Ice const &copy);

	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif