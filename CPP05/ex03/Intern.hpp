/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:53:52 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/23 11:24:52 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern 
{
	public:
		Intern();
		Intern(const Intern &i);
		~Intern();
		Intern &operator=(const Intern &i);

		AForm *makeForm(std::string name, std::string target);

		class UnknownFormNameExeception : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif