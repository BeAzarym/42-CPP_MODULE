/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:16:54 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/10 17:15:29 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "";
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	for (int i = 0; i < 100;i++)
		this->_ideas[i] = copy._ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
	std::cout << "Brain Assignement Operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
	return (*this);
}

std::string Brain::getIdea(int index)
{
	if (index > 100 || index < 0)
		return std::string("...");
	return (this->_ideas[index]);
}

void Brain::pushIdea(std::string idea)
{
	int i = 0;

	while (!this->_ideas[i].empty() && i < 100)
		i++;
	if (i < 100)
	{
		this->_ideas[i] = idea;
		return;
	}
	std::cout << "Brain is full, you can't add ideas anymore" << std::endl;
}

void Brain::replaceIdea(std::string idea, int index)
{
	if (index > 0 && index < 100)
		this->_ideas[index] = idea;
	else
	{
		std::cout << "Wrong index in replaceIdea" << std::endl;
	}
}
