/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:58:47 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/07 20:52:31 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* k = new WrongCat();

	std::cout << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	k->makeSound();

	std::cout << std::endl;
	delete meta;
	delete i;
	delete j;
	delete k;

	const Animal* random = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrongRandom = new WrongAnimal();
	const WrongCat *wrongCat = new WrongCat();

	std::cout << "Animal type: " << random->getType() << " and make this sound: " << std::endl;
	random->makeSound();
	std::cout << "Animal type: " << dog->getType() << " and make this sound: " << std::endl;
	dog->makeSound();
	std::cout << "Animal type: " << cat->getType() << " and make this sound: " << std::endl;
	cat->makeSound();
	std::cout << "Animal type: " << wrongRandom->getType() << " and make this sound: " << std::endl;
	wrongRandom->makeSound();
	std::cout << "Animal type: " << wrongCat->getType() << " and make this sound: " << std::endl;
	wrongCat->makeSound();

	delete random;
	delete dog;
	delete cat;
	delete wrongRandom;
	delete wrongCat;
}
