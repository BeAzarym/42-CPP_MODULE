/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:00:52 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/23 11:19:04 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		std::cout << std::endl << BOLD_BLUE << "Intern make Shrubbery" << RESET << std::endl;
		Intern intern;
		Bureaucrat executor("Executor", 1, 1);
		AForm *form;

		form = intern.makeForm("Shrubbery Creation", "shrubbery");
		executor.signForm(*form);
		executor.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << std::endl << BOLD_BLUE << "Intern make Robotomy" << RESET << std::endl;
		Intern intern;
		Bureaucrat executor("Executor", 1, 1);
		AForm *form;

		form = intern.makeForm("Robotomy Request", "robotomy");
		executor.signForm(*form);
		executor.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << std::endl << BOLD_BLUE << "Intern make Presidential Pardon" << RESET << std::endl;
		Intern intern;
		Bureaucrat executor("Executor", 1, 1);
		AForm *form;

		form = intern.makeForm("Presidential Pardon", "presidential");
		executor.signForm(*form);
		executor.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
		try
	{
		std::cout << std::endl << BOLD_BLUE << "Intern make unknown form" << RESET << std::endl;
		Intern intern;
		Bureaucrat random("Random", 150, 150);
		AForm *form;

		form = intern.makeForm("random", "random");
		random.signForm(*form);
		random.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}
