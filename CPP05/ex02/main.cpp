/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:00:52 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/22 15:44:58 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// SHRUBBERRY
	try
	{
		std::cout << std::endl << BOLD_BLUE << "Try success Shruberry" << RESET << std::endl;
		ShrubberyCreationForm shrubbery;

		Bureaucrat executor("Executor", 1, 1);

		executor.signForm(shrubbery);
		executor.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << std::endl << BOLD_BLUE << "Try fail grade too low Shruberry" << RESET << std::endl;
		ShrubberyCreationForm shrubbery;

		Bureaucrat executor("Executor", 150, 150);

		executor.signForm(shrubbery);
		executor.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << std::endl << BOLD_BLUE << "Try fail to exec Shruberry" << RESET << std::endl;
		ShrubberyCreationForm shrubbery;

		Bureaucrat executor("Executor", 1, 150);

		executor.signForm(shrubbery);
		executor.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << std::endl << BOLD_BLUE << "Try fail already sign Shruberry" << RESET << std::endl;
		ShrubberyCreationForm shrubbery;

		Bureaucrat executor("Executor", 1, 1);

		executor.signForm(shrubbery);
		executor.signForm(shrubbery);
		executor.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	// ROBOTOMY SUCCESS
	try
	{
		std::cout << std::endl << BOLD_BLUE << "Try success Robotomy" << RESET << std::endl;
		RobotomyRequestForm robotomy;

		Bureaucrat executor("Executor", 1, 1);

		executor.signForm(robotomy);
		executor.executeForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << std::endl << BOLD_BLUE << "Try fail grade too low Robotomy" << RESET << std::endl;
		RobotomyRequestForm robotomy;

		Bureaucrat executor("Executor", 150, 150);

		executor.signForm(robotomy);
		executor.executeForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << std::endl << BOLD_BLUE << "Try fail to exec Robotomy" << RESET << std::endl;
		RobotomyRequestForm robotomy;

		Bureaucrat executor("Executor", 1, 150);

		executor.signForm(robotomy);
		executor.executeForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << std::endl << BOLD_BLUE << "Try fail already sign Robotomy" << RESET << std::endl;
		RobotomyRequestForm robotomy;

		Bureaucrat executor("Executor", 1, 1);

		executor.signForm(robotomy);
		executor.signForm(robotomy);
		executor.executeForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	// PRESIDENTIAL SUCCESS
	try
	{
		std::cout << std::endl << BOLD_BLUE << "Try success PresidentialPardon" << RESET << std::endl;
		PresidentialPardonForm presidential;

		Bureaucrat executor("Executor", 1, 1);

		executor.signForm(presidential);
		executor.executeForm(presidential);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << std::endl << BOLD_BLUE << "Try fail grade too low PresidentialPardon" << RESET << std::endl;
		PresidentialPardonForm presidential;

		Bureaucrat executor("Executor", 150, 150);

		executor.signForm(presidential);
		executor.executeForm(presidential);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << std::endl << BOLD_BLUE << "Try fail already sign PresidentialPardon" << RESET << std::endl;
		PresidentialPardonForm presidential;

		Bureaucrat executor("Executor", 1, 1);

		executor.signForm(presidential);
		executor.signForm(presidential);
		executor.executeForm(presidential);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}
