/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:38:59 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/10 17:43:12 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const AAnimal *j = new Dog();
	const AAnimal *i = new Cat();

	delete j; //should not create a leak
	delete i;

	std::cout << std::endl;
	std::cout << "Own Test" << std::endl;
	std::cout << std::endl;

	const Dog *dog = new Dog();
	const Cat *cat = new Cat();

	Brain *dogBrain = dog->getBrain();
	Brain *catBrain = cat->getBrain();

	dogBrain->pushIdea("I NEED TO FOLLOW MY TAILS");
	std::cout << "dogBrain think about " << dogBrain->getIdea(0) << std::endl;
	catBrain->pushIdea("I NEED TO SLEEP");
	std::cout << "catBrain think about " << catBrain->getIdea(0) << std::endl;

	delete dog;
	delete cat;

	std::cout << std::endl;

	const AAnimal *x[8] = {new Dog(), new Dog(), new Dog(), new Dog(), new Cat(), new Cat(), new Cat(), new Cat()};

	for (int i = 0; i < 8; i++)
	{
		std::cout << "Animal _type: " << x[i]->getType() << " and making this noise: ";
		x[i]->makeSound();
	}

	for (int i = 0; i < 8; i++)
	{
		delete x[i];
	}

		return (0);
}
