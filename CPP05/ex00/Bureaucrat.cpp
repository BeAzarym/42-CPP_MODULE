/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:38:25 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/26 00:13:10 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150)
{
	std::cout << GREY << "Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade): _name(name), _grade(150)
{
	std::cout << GREY << "Assignement constructor called for " << name << RESET << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name), _grade(copy._grade)
{
	std::cout << GREY << "Copy constructor called for " << copy.getName() << RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << GREY << "Destructor called for " << this->_name << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << GREY << "Assignement Operator was called for " << this->getName() << RESET << std::endl;
	this->_grade = copy._grade;
	return (*this);
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int 		Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	return (out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".");
}

void Bureaucrat::incrementGrade(void)
{
	if (this->_grade <= 1)
		throw(Bureaucrat::GradeTooHighException());
	this->_grade--;
	std::cout << this->getName() << "grade was uppgraded to " << this->getGrade() << "." << std::endl;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->_grade >= 150)
		throw(Bureaucrat::GradeTooLowException());
	this->_grade++;
	std::cout << this->getName() << "grade was decreased to " << this->getGrade() <<  "." << std::endl;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: you can no more decrease the grade than 150.");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: you can no more increase the grade than 1.");
}
