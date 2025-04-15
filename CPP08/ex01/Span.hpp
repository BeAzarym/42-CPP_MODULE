/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:31:14 by cchabeau          #+#    #+#             */
/*   Updated: 2025/04/10 13:26:37 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cstdlib>  
#include <ctime> 


class Span
{
	private:
		unsigned int 				_bufferSize;
		std::vector<int>	_buffer;

	public:
		Span(unsigned int bufferSize);
		Span(const Span &x);
		~Span();
		Span &operator=(const Span &x);
		
		void addNumber(int n);
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int longestSpan();
		unsigned int shortestSpan();
		
		void fillRandomBuffer(int min, int max);
		void printBuffer();

		class BufferFullException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class BufferTooFewException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif