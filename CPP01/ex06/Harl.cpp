/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:20:58 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/14 12:58:53 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}
void Harl::complain(std::string level)
{
	int i;
	bool status = true;
	void (Harl::*func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string string[4] = {std::string("DEBUG"), std::string("INFO"), std::string("WARNING"), std::string("ERROR")};
	
	for (i = 0; i < 4;i++)
	{	
		if (string[i] == level)
		{
			status = false;
			break;
		}
	}
	if (status)
		std::cout << "Invalid level Error" << std::endl;
	switch (i)
	{
		case 0:
			(this->*func[i++])();
			
		case 1:
			(this->*func[i++])();
			
		case 2:
			(this->*func[i++])();
			
		case 3:
			(this->*func[i++])();
			
		default:
			break;
	}
	
	if (status)
		std::cout << "Invalid level Error" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}
