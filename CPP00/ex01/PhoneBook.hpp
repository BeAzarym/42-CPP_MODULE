/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:05:10 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/13 16:10:17 by cchabeau         ###   ########.fr       */
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
	Contact _Contacts[8];
	int _Size;
	int _Pos;

	std::string _formateData(std::string str);
	std::string _getDataFromInput(std::string Data);
	void _printPhoneBook();
	void _printContact(int index);

  public:
	PhoneBook();
	~PhoneBook();

	void add();
	void search();
};

#endif