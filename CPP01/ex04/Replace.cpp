/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:29:07 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/03 20:14:27 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace()
{
}
Replace::Replace(std::string infile, std::string s1, std::string s2)
{
	std::string outfile = infile + ".replace";
	this->_Infile.open(infile, std::fstream::in);
	if ((this->_Infile.rdstate() & std::fstream::failbit) != 0)
	{
		std::cout << "Error: Can't open " << infile << std::endl;
		delete this;
		exit(EXIT_FAILURE);
	}
	this->_Outfile.open(outfile, std::fstream::out);
	if ((this->_Outfile.rdstate() & std::fstream::failbit) != 0)
	{
		std::cout << "Error: Can't open " << outfile << std::endl;
		delete this;
		exit(EXIT_FAILURE);
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

	std::string Nounouille;
	std::getline(this->_Infile, Nounouille);
	if ((this->_Infile.rdstate() & std::fstream::eofbit) != 0)
		return (Nounouille);
	index = Nounouille.find(this->_s1, 0);
	while (index != std::string::npos)
	{
		Nounouille.erase(index, this->_s1.size());
		Nounouille.insert(index, this->_s2);
		index = Nounouille.find(this->_s1, index + this->_s1.size());
	}
	return (Nounouille);
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
