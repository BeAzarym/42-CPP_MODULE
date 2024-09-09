/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:00:52 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/26 11:33:13 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		std::cout << BOLD_BLUE << ">> Try to sign with insufficient grade. <<" << RESET << std::endl << std::endl;
		Bureaucrat master("Master", 2);
		Form contrat("Standard Form", 1, 1);

		std::cout << contrat << std::endl;
		std::cout << master << std::endl;

		master.signForm(contrat);
	}
	catch(std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl << std::endl;
	}

	try
	{
		std::cout << BOLD_BLUE << ">> Try to sign with sufficient grade. <<" << RESET << std::endl << std::endl;
		
		Bureaucrat master("Master", 1);
		Form contrat("Standard Form", 1, 1);

		std::cout << contrat << std::endl;
		std::cout << master << std::endl;

		master.signForm(contrat);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << "\033[0m" << std::endl << std::endl;
	}

	try
	{
		std::cout << BOLD_BLUE << ">> Try to sign a form already signed. <<" << RESET << std::endl << std::endl;

		Bureaucrat master("Master", 1);
		Bureaucrat intern("Intern", 150);

		Form contrat("Standard Form", 150, 150);

		std::cout << contrat << std::endl;
		std::cout << master << std::endl;
		std::cout << intern << std::endl;

		master.signForm(contrat);
		intern.signForm(contrat);
	}
	catch (std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl << std::endl;
	}
}
