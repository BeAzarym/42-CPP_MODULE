/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:12:54 by cchabeau          #+#    #+#             */
/*   Updated: 2025/04/10 13:28:45 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _bufferSize(n) {};

Span::Span(const Span &x)
{
	(*this) = x;
}

Span &Span::operator=(const Span &x)
{
	if (this != &x)
	{
		this->_bufferSize = x._bufferSize;
		this->_buffer = x._buffer;
	}
	return (*this);
}

Span::~Span(){};

void Span::addNumber(int n)
{
	if (this->_buffer.size() >= this->_bufferSize)
		throw Span::BufferFullException();
	this->_buffer.push_back(n);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if ((this->_buffer.size() + std::distance(begin, end)) >= this->_bufferSize)
		throw Span::BufferFullException();
	this->_buffer.insert(this->_buffer.begin(), begin, end);
}

unsigned int Span::longestSpan()
{
	if (this->_buffer.size() < 2)
		throw Span::BufferTooFewException();
	std::vector<int>::iterator min = std::min_element(this->_buffer.begin(), this->_buffer.end());
	std::vector<int>::iterator max = std::max_element(this->_buffer.begin(), this->_buffer.end());

	return (*max - *min);
}

unsigned int Span::shortestSpan()
{
	if (this->_buffer.size() < 2)
		throw Span::BufferTooFewException();
	
	std::vector<int> sortedBuffer = this->_buffer;
	std::sort(sortedBuffer.begin(), sortedBuffer.end());

	unsigned int max = longestSpan();
	for (std::vector<int>::iterator it = sortedBuffer.begin(); it != sortedBuffer.end();it++)
	{
		int res = *(it + 1) - *it;
		if (static_cast<unsigned int>(res) < max)
			max = static_cast<unsigned int>(res);
	}
	return (max);
}

void Span::fillRandomBuffer(int min, int max)
{
	   this->_buffer.clear();

    for (unsigned int i = 0; i < this->_bufferSize; ++i) {
        int number = min + std::rand() % (max - min + 1);
        this->_buffer.push_back(number);
    }
}

void Span::printBuffer()
{
	std::cout << "BUFFER: ";
	for (unsigned int i = 0; i < this->_bufferSize; i++)
	{
		std::cout << this->_buffer[i] << " ";
	}
	std::cout << std::endl;
}

const char *Span::BufferFullException::what() const throw()
{
	return ("[SPAN] [ERROR] Buffer Full.");
}

const char *Span::BufferTooFewException::what() const throw()
{
	return ("[SPAN] [ERROR] Buffer too Few.");
}