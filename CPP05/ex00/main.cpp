/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:00:52 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/25 22:28:01 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		std::cout << BOLD_BLUE << ">> Try increase highest grade. <<" << RESET << std::endl << std::endl;
		Bureaucrat master("Master", 1);

		std::cout << master << std::endl;

		master.incrementGrade();
	}
	catch(std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl << std::endl;
	}

	try
	{
		std::cout << BOLD_BLUE << ">> Try decrease lowest grade. <<" << RESET << std::endl << std::endl;
		
		Bureaucrat servant("Servant", 150);
		
		std::cout << servant << std::endl;
		
		servant.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << "\033[0m" << std::endl << std::endl;
	}

	try
	{
		std::cout << BOLD_BLUE << ">> Try correct use. <<" << RESET << std::endl << std::endl;

		Bureaucrat master("Master", 2);
		Bureaucrat servant("Servant", 149);

		std::cout << std::endl << master << std::endl;
		std::cout << servant << std::endl << std::endl;

		master.incrementGrade();
		servant.decrementGrade();

		std::cout << std::endl << master << std::endl;
		std::cout << servant << std::endl << std::endl;		
	}
	catch (std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl << std::endl;
	}
}
