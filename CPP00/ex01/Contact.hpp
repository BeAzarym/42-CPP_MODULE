/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:05:36 by cchabeau          #+#    #+#             */
/*   Updated: 2024/02/29 15:39:31 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>

class Contact
{
	private: 

	std::string _FirstName;
	std::string _LastName;
	std::string _Nickname;
	std::string _PhoneNumber;
	std::string _Secret;

	public:

	Contact();
	Contact(std::string FirstName, std::string LastName, std::string Nickname, std::string PhoneNumber, std::string Secret);
	~Contact();

	void setFirstName(std::string FirstName);
	void setLastName(std::string LastName);
	void setNickname(std::string Nickname);
	void setPhoneNumber(std::string PhoneNumber);
	void setSecret(std::string Secret);

	std::string getFirstName();
	std::string getLastName();
	std::string getNickname();
	std::string getPhoneNumber();
	std::string getSecret();
};

#endif