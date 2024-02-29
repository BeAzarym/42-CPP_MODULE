/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:05:20 by cchabeau          #+#    #+#             */
/*   Updated: 2024/02/29 15:43:11 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_Pos = 0;
	this->_Size = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "DESTRUCTOR CALLED" << std::endl;
}

std::string PhoneBook::_getDataFromInput(std::string Data)
{
	std::string input;
	std::cout << Data << ": ";
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Input empty" << std::endl;
		std::getline(std::cin, input);
	}
	return (input);
}

void PhoneBook::add()
{
	if (this->_Size == 8)
	{
		this->_Pos = 0;
		this->_Size--;
	}
	this->_Contacts[this->_Pos].setFirstName(_getDataFromInput("first name"));
	this->_Contacts[this->_Pos].setLastName(_getDataFromInput("last name"));
	this->_Contacts[this->_Pos].setNickname(_getDataFromInput("nickname"));
	this->_Contacts[this->_Pos].setPhoneNumber(_getDataFromInput("phonenumber"));
	this->_Contacts[this->_Pos].setSecret(_getDataFromInput("darkest secret"));
	this->_Size++;
	this->_Pos++;
}
void PhoneBook::search()
{
	if (this->_Size < 1)
	{
		std::cout << "You don't have any contact." << std::endl;
		return ;
	}
	
	std::string str;
	this->_printPhoneBook();
	std::cout << "Enter the index: " << std::endl;
	std::getline(std::cin, str);
	while(str.empty() || !isdigit(str[0]))
	{
		std::cout << "Invalid Index, please retry" << std::endl;
		std::getline(std::cin, str);
	}
	this->_printContact(std::stoi(str));
	return ;
}

void PhoneBook::_printContact(int index)
{
	std::cout << "First Name: " << this->_Contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->_Contacts[index].getLastName() << std::endl;
	std::cout << "Nickname:" << this->_Contacts[index].getNickname() << std::endl;
	std::cout << "PhoneNumber: " << this->_Contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->_Contacts[index].getSecret() << std::endl;
}

void	PhoneBook::_printPhoneBook(void)
{
	std::cout << "+-------------------------------------------+" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "+-------------------------------------------+" << std::endl;
	for (int i = 0; i < this->_Size; i++)
	{
		std::string firstname = this->_formateData(this->_Contacts[i].getFirstName());
		std::string lastname = this->_formateData(this->_Contacts[i].getLastName());
		std::string nickname = this->_formateData(this->_Contacts[i].getNickname());
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << firstname << "|";
		std::cout << std::setw(10) << lastname << "|";
		std::cout << std::setw(10) << nickname << std::endl;
	}
	
}

std::string PhoneBook::_formateData(std::string str)
{
	int	size;

	std::string formated;
	size = str.size();
	if (size > 10)
	{
		formated = str.substr(0, 9);
		formated.append(".");
		return (formated);
	}
	return (str);
}
