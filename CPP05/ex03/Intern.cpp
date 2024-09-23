/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:02:05 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/23 11:24:46 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << GREY << "[Intern] Default constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern &i)
{
	std::cout << GREY << "[Intern] Copy constructor called" << RESET << std::endl;
	*this = i;
}

Intern::~Intern()
{
	std::cout << GREY << "[Intern] Destructor called" << RESET << std::endl;
}

Intern &Intern::operator=(const Intern &i)
{
	std::cout << GREY << "[Intern] Assignement operator called" << RESET << std::endl;
	if (this == &i)
		return (*this);
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string form[] = {"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};
	int formId = -1;

	for (int i = 0; i < 3; i++)
	{
		if (name.compare(form[i]) == 0)
			formId = i;
	}

	switch(formId)
	{
		case 0:
			std::cout << "Intern creates " << name << " form." << std::endl;
			return (new PresidentialPardonForm(target));
			break;
		case 1:
			std::cout << "Intern creates " << name << " form." << std::endl;
			return (new RobotomyRequestForm(target));
			break;
		case 2:
			std::cout << "Intern creates " << name << " form." << std::endl;
			return (new ShrubberyCreationForm(target));
			break;
		default:
			throw(UnknownFormNameExeception());
		}
}

const char *Intern::UnknownFormNameExeception::what() const throw()
{
	return ("Error: unknown form type.");
}