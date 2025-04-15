/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:24:57 by cchabeau          #+#    #+#             */
/*   Updated: 2025/04/15 14:57:23 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream fs;
	std::string buffer;

	fs.open("data.csv", std::ios::in);
	if (!fs.is_open())
		throw BitcoinExchange::FailedToLoadCSV();
	std::getline(fs, buffer);
	while (!fs.eof())
	{
		std::getline(fs, buffer);
		if (buffer.empty())
			continue;
		size_t pos = buffer.find(',');
		std::string date = buffer.substr(0, pos);
		float value = std::strtof(buffer.substr(pos + 1).c_str(), NULL);
		this->_buffer.insert(std::pair<std::string, float>(date, value));
	}
	fs.close();
	std::cout << "[INFO] Data csv file loaded with success." << std::endl;
}

BitcoinExchange::~BitcoinExchange(){};

void BitcoinExchange::computeValue(const std::string &inputFile)
{
	std::ifstream fs;
	std::string buffer;
	std::map<std::string, float> input;

	fs.open(inputFile.c_str());
	if (!fs.is_open())
	{
		std::cerr << "[ERROR] Failed to open " << inputFile << "." << std::endl;
		return;
	}
	
	std::getline(fs, buffer);
	if (buffer != "date | value")
	{
		std::cerr << "[ERROR] Input file badly formatted: " << std::endl << buffer << std::endl;
		return;
	}
	
	while (!fs.eof())
	{
		std::getline(fs, buffer);
		input = _parseInput(buffer);
		if (!input.empty())
			_findChange(input);
	}
}

void BitcoinExchange::_findChange(std::map<std::string, float> input)
{
	std::map<std::string, float>::iterator buffer_it;
	std::map<std::string, float>::iterator input_it = input.begin();

	buffer_it = this->_buffer.lower_bound(input_it->first);
	std::cout << input_it->first << " => " <<  input_it->second << " = " << (buffer_it->second * input_it->second) << std::endl;
}

std::map<std::string, float> BitcoinExchange::_parseInput(std::string &str)
{
	std::map<std::string, float> result;
	std::string date;
	float value;
	
	size_t pos = str.find('|');
	if (pos == std::string::npos)
	{
		std::cout << "Error: bad input => " << str << std::endl;
		return std::map<std::string, float>();
	}
	
	date = str.substr(0, pos - 1);
	if (!_isDateValid(date))
	{
		std::cout << "Error: bad input => " << str << std::endl;
		return std::map<std::string, float>();
	}
	
	value = strtof(str.substr(pos + 1).c_str(), NULL);
	if (value < 0 || value > 1000)
	{
		std::cout << (value < 0 ? "Error: not a positive number." : "Error: too large a number.") << std::endl;
		return std::map<std::string, float>();
	}
	
	result.insert(make_pair(date, value));
	return result;
}

bool	BitcoinExchange::_isDateValid(const std::string &str)
{
	int years, month, day;
	
	if (str.size() != 10)
		return false;
	years = std::atoi(str.substr(0, 4).c_str());
	month = std::atoi(str.substr(5, 7).c_str());
	day = std::atoi(str.substr(8, 10).c_str());

	std::tm timeinfo = {};
	timeinfo.tm_year = years - 1900;
	timeinfo.tm_mon = month - 1;
	timeinfo.tm_mday = day;


	std::tm copy = timeinfo;
	if (std::mktime(&timeinfo) == -1)
		return false;

	return (timeinfo.tm_year == copy.tm_year && timeinfo.tm_mon == copy.tm_mon && timeinfo.tm_mday == copy.tm_mday);
}

const char *BitcoinExchange::FailedToLoadCSV::what() const throw()
{
	return ("[ERROR] Failed to open data csv file.");
}
