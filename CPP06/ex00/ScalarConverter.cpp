/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:20:08 by cchabeau          #+#    #+#             */
/*   Updated: 2024/11/26 21:18:07 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void){}

ScalarConverter::~ScalarConverter(void){}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) 
{
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	return *this;
}


int ScalarConverter::_detectType(std::string str)
{
	if (str == "nan" || str == "-inf" || str == "+inf" || str == "nanf" || str == "+inff" || str == "-inff")
		return LITERAL;

	size_t length = str.size();
	if (length == 1 && isdigit(str.at(0)) == false)
		return CHAR;
	else if (length == 1 && isdigit(str.at(0)) == true)
		return INT;

	if (str.at(0) != '+' && str.at(0) != '-' && str.at(0) != '.' && isdigit(str.at(0)) == false)
		return INVALID;

	int dotEncounter = 0;
	for (size_t i = 1; i < str.size(); i++)
	{
		if (str.at(i) == '.')
		{
			dotEncounter++;
			if (dotEncounter > 1 || str.at(i+1) == 'f' || str.at(i+1) == '\0')
				return INVALID;
		}
		else if (str.compare(str.size() - 1, 1, "f") == 0)
			return FLOAT;
		else if (isdigit(str.at(i)) == false)
			return INVALID;
	}
	
	if (dotEncounter)
		return DOUBLE;
	else
		return INT;
}

void ScalarConverter::convert(std::string str)
{
	switch (_detectType(str))
	{
	case CHAR:
		_convertToChar(str);
		break;

	case INT:
		_convertToInt(str);
		break;
		
	case FLOAT:
		_convertToFloat(str);
		break;

	case DOUBLE:
		_convertToDouble(str);
		break;
	case LITERAL:
		_convertToLiteral(str);
		break;
	default:
		std::cout << RED << "Error : Invalid type" << RESET << std::endl;
		break;
	}
}

void ScalarConverter::_convertToChar(std::string str)
{
	char c = str.at(0);
	
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" <<std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::_convertToInt(std::string str)
{
	int x;
	std::stringstream intStream(str);
	
	intStream >> x;
	if (intStream.fail())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: overflow" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	if (x >= 32 && x <= 126)
		std::cout << "char: '" << static_cast<char>(x) <<"'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	std::cout << "int: " << x << std::endl;
	std::cout << "float: " << static_cast<float>(x) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(x) << ".0" << std::endl;
	
}

void ScalarConverter::_convertToFloat(std::string str)
{
	float x;
	std::stringstream floatStream(str);

	floatStream >> x;
	if (floatStream.fail())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: overflow" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	if (static_cast<int>(x) >= 32 && static_cast<int>(x) <= 126)
		std::cout << "char: '" << static_cast<char>(x) <<"'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	
	if (static_cast<int>(x) < INT_MIN || static_cast<int>(x) > INT_MAX)
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(x) << std::endl;
	
	if (x == static_cast<int>(x))
	{
		std::cout << "float: " << x << ".0f" << std::endl;
		std::cout << "double " << static_cast<double>(x) << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << x << "f" << std::endl;
		std::cout << "double " << static_cast<double>(x) << std::endl;
	}
	
}

void ScalarConverter::_convertToDouble(std::string str)
{
	double x;
	std::stringstream doubleStream(str);

	doubleStream >> x;
	if (doubleStream.fail())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: overflow" << std::endl;
		return;
	}

	if (static_cast<int>(x) >= 32 && static_cast<int>(x) <= 126)
		std::cout << "char: '" << static_cast<char>(x) <<"'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	
	if (static_cast<int>(x) < INT_MIN || static_cast<int>(x) > INT_MAX)
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(x) << std::endl;
	
	if (x == static_cast<int>(x))
	{
		std::cout << "float: " << static_cast<float>(x) << ".0f" << std::endl;
		std::cout << "double " << x << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(x) << "f" << std::endl;
		std::cout << "double " << x << std::endl;
	}
}

void ScalarConverter::_convertToLiteral(std::string str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	
	if (str.at(0) == '+')
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str.at(0) == '-')
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;	
	}
	else
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		
	}
}
