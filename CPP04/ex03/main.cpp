/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:32:07 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/10 20:00:27 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main(void)
{
	std::cout << "SUBJECT MAIN" << std::endl << std::endl;

	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << "PERSONNAL MAIN" << std::endl << std::endl;
	
	IMateriaSource *tmpSrc = new MateriaSource();
	tmpSrc->learnMateria(new Ice());
	tmpSrc->learnMateria(new Cure());
	ICharacter *character = new Character("Paul");
	AMateria *tmpMateria;
	tmpMateria = tmpSrc->createMateria("ice");
	character->equip(tmpMateria);
	tmpMateria = tmpSrc->createMateria("molted ice");
	character->equip(tmpMateria);
	ICharacter *poutch = new Character("Poutch");
	character->use(0, *poutch);
	character->use(1, *poutch);
	delete tmpSrc;
	delete poutch;
	delete character;

	return (0);
}