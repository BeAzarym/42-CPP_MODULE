/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:24:33 by cchabeau          #+#    #+#             */
/*   Updated: 2025/04/15 14:55:22 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <ctime>
#include <fstream>
#include <iostream>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _buffer;

		std::map<std::string, float>	_parseInput(std::string &str);
		bool 							_isDateValid(const std::string &str);
		void _findChange(std::map<std::string, float> input);

	public:
		BitcoinExchange();
		~BitcoinExchange();

		void computeValue(const std::string &inputFile);

		class FailedToLoadCSV : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif