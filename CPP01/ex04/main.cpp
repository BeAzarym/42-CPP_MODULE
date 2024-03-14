/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:13:37 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/14 12:36:09 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: Invalid argument count" << std::endl;
		return (1);
	}

	std::fstream in;
	std::string infile = argv[1];

	in.open(infile.c_str(), std::fstream::in);
	if ((in.rdstate() & std::fstream::failbit) != 0)
	{
		std::cout << "Error: Can't open " << infile << std::endl;
		return 1;
	}

	Replace *toReplace = new Replace(argv[1], argv[2], argv[3]);
	toReplace->Transform();
	delete toReplace;
}