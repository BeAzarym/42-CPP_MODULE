/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 11:54:40 by cchabeau          #+#    #+#             */
/*   Updated: 2024/11/26 20:52:36 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <limits.h>

# define RED "\033[31m"
# define GREY "\033[90m"
# define BOLD_BLUE "\033[1;34m"
# define RESET "\033[0m"

enum e_type
{
	INVALID = 0,
	CHAR = 1,
	INT = 2,
	FLOAT = 3,
	DOUBLE = 4,
	LITERAL = 5,
};

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter(void);
		
		ScalarConverter &operator=(const ScalarConverter &copy);
		
		static int _detectType(std::string str);
		static void _convertToChar(std::string str);
		static void _convertToInt(std::string str);
		static void _convertToFloat(std::string str);
		static void _convertToDouble(std::string str);
		static void _convertToLiteral(std::string str);



	public:
		static void convert(std::string str);
};

#endif