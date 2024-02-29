/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:05:32 by cchabeau          #+#    #+#             */
/*   Updated: 2024/02/29 15:43:28 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(std::string FirstName, std::string LastName,
		std::string Nickname, std::string PhoneNumber, std::string Secret)
{
	this->_FirstName = FirstName;
	this->_LastName = LastName;
	this->_Nickname = Nickname;
	this->_PhoneNumber = PhoneNumber;
	this->_Secret = Secret;
}

Contact::~Contact()
{
	std::cout << "DESTRUCTOR CALLED" << std::endl;
}

void Contact::setFirstName(std::string FirstName)
{
	this->_FirstName = FirstName;
}
void Contact::setLastName(std::string LastName)
{
	this->_LastName = LastName;
}
void Contact::setNickname(std::string Nickname)
{
	this->_Nickname = Nickname;
}
void Contact::setPhoneNumber(std::string PhoneNumber)
{
	this->_PhoneNumber = PhoneNumber;
}
void Contact::setSecret(std::string Secret)
{
	this->_Secret = Secret;
}

std::string Contact::getFirstName()
{
	return this->_FirstName;
}
std::string Contact::getLastName()
{
	return this->_LastName;
}
std::string Contact::getNickname()
{
	return this->_Nickname;
}

std::string Contact::getPhoneNumber()
{
	return this->_PhoneNumber;
}
std::string Contact::getSecret()
{
	return this->_Secret;
}
