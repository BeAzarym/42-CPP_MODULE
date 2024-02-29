/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:05:20 by cchabeau          #+#    #+#             */
/*   Updated: 2024/02/29 15:30:22 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->Pos = 0;
	this->Size = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "DESTRUCTOR CALLED" << std::endl;
}

std::string PhoneBook::getDataFromInput(std::string Data)
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
	if (this->Size == 8)
	{
		this->Pos = 0;
		this->Size--;
	}
	this->Contacts[this->Pos].setFirstName(getDataFromInput("first name"));
	this->Contacts[this->Pos].setLastName(getDataFromInput("last name"));
	this->Contacts[this->Pos].setNickname(getDataFromInput("nickname"));
	this->Contacts[this->Pos].setPhoneNumber(getDataFromInput("phonenumber"));
	this->Contacts[this->Pos].setSecret(getDataFromInput("darkest secret"));
	this->Size++;
	this->Pos++;
}
void PhoneBook::search()
{
	if (this->Size < 1)
	{
		std::cout << "You don't have any contact." << std::endl;
		return ;
	}
	
	std::string str;
	this->printPhoneBook();
	std::cout << "Enter the index: " << std::endl;
	std::getline(std::cin, str);
	while(str.empty() || !isdigit(str[0]))
	{
		std::cout << "Invalid Index, please retry" << std::endl;
		std::getline(std::cin, str);
	}
	this->printContact(std::stoi(str));
	return ;
}

void PhoneBook::printContact(int index)
{
	std::cout << "First Name: " << this->Contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->Contacts[index].getLastName() << std::endl;
	std::cout << "Nickname:" << this->Contacts[index].getNickname() << std::endl;
	std::cout << "PhoneNumber: " << this->Contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->Contacts[index].getSecret() << std::endl;
}

void	PhoneBook::printPhoneBook(void)
{
	std::cout << "+-------------------------------------------+" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "+-------------------------------------------+" << std::endl;
	for (int i = 0; i < this->Size; i++)
	{
		std::string firstname = this->formateData(this->Contacts[i].getFirstName());
		std::string lastname = this->formateData(this->Contacts[i].getLastName());
		std::string nickname = this->formateData(this->Contacts[i].getNickname());
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << firstname << "|";
		std::cout << std::setw(10) << lastname << "|";
		std::cout << std::setw(10) << nickname << std::endl;
	}
	
}

std::string PhoneBook::formateData(std::string str)
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
