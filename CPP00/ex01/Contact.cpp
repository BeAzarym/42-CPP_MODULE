/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:05:32 by cchabeau          #+#    #+#             */
/*   Updated: 2024/02/26 16:05:33 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::Contact(std::string FirstName, std::string LastName,
		std::string Nickname, std::string PhoneNumber, std::string Secret)
{
	this->FirstName = FirstName;
	this->LastName = LastName;
	this->Nickname = Nickname;
	this->PhoneNumber = PhoneNumber;
	this->Secret = Secret;
}

Contact::~Contact()
{
	std::cout << "DESTRUCTOR CALLED" << std::endl;
}

void Contact::setFirstName(std::string FirstName)
{
	this->FirstName = FirstName;
}
void Contact::setLastName(std::string LastName)
{
	this->LastName = LastName;
}
void Contact::setNickname(std::string Nickname)
{
	this->Nickname = Nickname;
}
void Contact::setPhoneNumber(std::string PhoneNumber)
{
	this->PhoneNumber = PhoneNumber;
}
void Contact::setSecret(std::string Secret)
{
	this->Secret = Secret;
}

std::string Contact::getFirstName()
{
	return this->FirstName;
}
std::string Contact::getLastName()
{
	return this->LastName;
}
std::string Contact::getNickname()
{
	return this->Nickname;
}

std::string Contact::getPhoneNumber()
{
	return this->PhoneNumber;
}
std::string Contact::getSecret()
{
	return this->Secret;
}
