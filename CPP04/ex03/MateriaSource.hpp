/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 18:36:45 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/10 19:51:22 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

#include <string>
#include <iostream>

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_inventory[4];
	
	public:
		MateriaSource();
		MateriaSource( MateriaSource const &copy);
		~MateriaSource();

		const MateriaSource &operator=( MateriaSource const &copy);

		virtual void learnMateria(AMateria *Materia);
		virtual AMateria *createMateria(std::string const &type);
};

#endif