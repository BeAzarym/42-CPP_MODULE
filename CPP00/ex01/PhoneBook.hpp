/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:05:10 by cchabeau          #+#    #+#             */
/*   Updated: 2024/02/29 15:22:08 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <iostream>
# include <string>

class PhoneBook
{
  private:
	Contact Contacts[8];
	int Size;
	int Pos;

	std::string formateData(std::string str);
	std::string getDataFromInput(std::string Data);
	void printPhoneBook();
	void printContact(int index);

  public:
	PhoneBook();
	~PhoneBook();

	void add();
	void search();
};

#endif