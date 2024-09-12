/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:38:25 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/12 16:03:18 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _gradeSign(150), _gradeExec(150)
{
	std::cout << GREY << "[Bureaucrat] Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade): _name(name), _gradeSign(150), _gradeExec(150)
{
	std::cout << GREY << "[Bureaucrat] Assignement constructor called for " << name << RESET << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec)
{
	std::cout << GREY << "[Bureaucrat] Copy constructor called for " << copy.getName() << RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << GREY << "[Bureaucrat] Destructor called for " << this->_name << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << GREY << "[Bureaucrat] Assignement Operator was called for " << this->getName() << RESET << std::endl;
	this->_gradeSign = copy._gradeSign;
	this->_gradeExec = copy._gradeExec;
	return (*this);
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int 		Bureaucrat::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int			Bureaucrat::getGradeExec(void) const
{
	return (this->_gradeExec);
}


std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	return (out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGradeSign() << ".");
}

void Bureaucrat::incrementGrade(void)
{
	if (this->_grade <= 1)
		throw(Bureaucrat::GradeTooHighException());
	this->_grade--;
	std::cout << this->getName() << "grade was uppgraded to " << this->getGradeSign() << "." << std::endl;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->_grade >= 150)
		throw(Bureaucrat::GradeTooLowException());
	this->_grade++;
	std::cout << this->getName() << "grade was decreased to " << this->getGradeSign() <<  "." << std::endl;
}

void Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << "has signed the form called " << form.getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << RED << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << RESET << std::endl;
	}
}

void Bureaucrat::executeForm(AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << "executed " << form.getName() << "." << std::endl; 
	}
	catch(const std::exception& e)
	{
		std::cout << RED << this->getName() << "couldn't execute form " << form.getName() << " because " << e.what() << RESET << std::endl; 
	}
	
}


const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: you can no more decrease the grade than 150.");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: you can no more increase the grade than 1.");
}
