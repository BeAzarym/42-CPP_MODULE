/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:29:07 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/14 12:29:16 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace()
{
}
Replace::Replace(std::string infile, std::string s1, std::string s2)
{
	std::string outfile = infile + ".replace";
	this->_Infile.open(infile.c_str(), std::fstream::in);
	if ((this->_Infile.rdstate() & std::fstream::failbit) != 0)
	{
		std::cout << "Error: Can't open " << infile << std::endl;
		return;
	}
	this->_Outfile.open(outfile.c_str(), std::fstream::out);
	if ((this->_Outfile.rdstate() & std::fstream::failbit) != 0)
	{
		std::cout << "Error: Can't open " << outfile << std::endl;
		return;
	}
	this->_s1 = s1;
	this->_s2 = s2;
}
Replace::~Replace()
{
	this->_Infile.close();
	this->_Outfile.close();
}

std::string Replace::Replaceline(void)
{
	size_t	index;

	std::string line;
	std::getline(this->_Infile, line);
	if ((this->_Infile.rdstate() & std::fstream::eofbit) != 0)
		return (line);
	index = line.find(this->_s1, 0);
	while (index != std::string::npos)
	{
		line.erase(index, this->_s1.size());
		line.insert(index, this->_s2);
		index = line.find(this->_s1, index + this->_s2.size());
	}
	return (line);
}

void Replace::Transform(void)
{
	std::string line;

	while (1)
	{
		line = Replaceline();
		if ((this->_Infile.rdstate() & std::fstream::eofbit) != 0)
			return;
		this->_Outfile << line << std::endl;
	}
}
