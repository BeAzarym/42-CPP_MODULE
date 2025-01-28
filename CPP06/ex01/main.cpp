/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:17:31 by cchabeau          #+#    #+#             */
/*   Updated: 2025/01/28 14:14:46 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


int main()
{
	Data data;
	Data *ptr;
	uintptr_t raw;

	data.string = "Hello World!";
	data.length = 12;

	std::cout << BOLD_BLUE << "Data : [" << RESET << data.string << ", " << data.length << BOLD_BLUE << "]" << RESET << std::endl;
	std::cout << BOLD_BLUE << "Adress: [" << RESET << &data << BOLD_BLUE <<"]" << RESET << std::endl;
	
	raw = Serializer::serialize(&data);
	ptr = Serializer::deserialize(raw);

	std::cout << BOLD_BLUE << "Data : [" RESET << ptr->string << ", " << ptr->length << BOLD_BLUE << "]" << RESET << std::endl;
	std::cout << BOLD_BLUE << "Adress: [" << RESET << ptr << BOLD_BLUE << "]" << RESET << std::endl;
	
}