/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:26:52 by cchabeau          #+#    #+#             */
/*   Updated: 2025/04/23 10:14:41 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RED "\033[31m"
# define GREY "\033[90m"
# define BOLD_BLUE "\033[1;34m"
# define RESET "\033[0m"

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <ctime>
#include <cstdlib>
#include <iostream>


Base *create (void)
{
	int x = std::rand() % 3;
	Base *base;
	
	switch (x)
	{
		case (0):
			std::cout << GREY << "A Class was created" << RESET << std::endl;
			base = new A();
			break;
			
		case (1):
			std::cout << GREY << "B Class was created" << RESET << std::endl;
			base = new B();
			break;
		
		case (2):
			std::cout << GREY << "C Class was created" << RESET << std::endl;
			base = new C();
			break;
		
		default:
			std::cout << RED << "A bug was found in the matrix" << RESET << std::endl;
			base = NULL;
			break;
	}
	return (base);
}

void identification(Base *base)
{
	A *TypeA = dynamic_cast<A *>(base);
	if (TypeA)
		std::cout << "Identification is formal, the type is A." << std::endl;
	B *TypeB = dynamic_cast<B *>(base);
	if (TypeB)
		std::cout << "Identification is formal, the type is B." << std::endl;
	C *TypeC = dynamic_cast<C *>(base);
	if (TypeC)
		std::cout << "Identification is formal, the type is C." << std::endl;
	if (!TypeA && !TypeB && !TypeC)
		std::cout << RED << "Identification has failed." << RESET << std::endl;
}

void identification(Base &base)
{
	try
	{
		A &TypeA = dynamic_cast<A &>(base);
		(void)TypeA;
		std::cout << "Identification is formal, the type is A." << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	
	try
	{
		B &TypeB = dynamic_cast<B &>(base);
		(void)TypeB;
		std::cout << "Identification is formal, the type is B." << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	try
	{
		C &TypeC = dynamic_cast<C &>(base);
		(void)TypeC;
		std::cout << "Identification is formal, the type is C." << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

int main()
{
	std::srand(std::time(NULL));

	Base *base = create();
	identification(base);
	identification(*base);
	delete base;
}