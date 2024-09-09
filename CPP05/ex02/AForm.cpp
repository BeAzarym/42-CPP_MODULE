/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:35:39 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/02 15:48:48 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

	AForm::AForm(void): _name("Default"), _gradeSign(1), _gradeExec(1), _target("Default"), _isSigned(false)
	{
		std::cout << GREY << "AForm Default constructor called" << RESET << std::endl;
	}

	AForm::AForm(const std::string name, const int gradeSign, const int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _isSigned(false), _target("Default")
	{
		std::cout << GREY << "AForm Assignement constructor called for " << this->getName() ²<< RESET << std::endl;
		if (gradeSign < 1 || gradeExec < 1)
			throw GradeTooHighException();
		if (gradeSign > 150 || gradeExec > 150)
			throw GradeTooLowException();
	}

	AForm::AForm(const AForm &copy) : _name(copy._name), _target(copy._target), _isSigned(false), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec)
	{
		std::cout << GREY << "AForm Copy Assignement constructor called for " << this->getName() << RESET << std::endl;
	}

	AForm::~AForm()

	{
		std::cout << GREY << "AForm Destructor called for " << this->getName() << RESET << std::endl;
	}

	AForm &AForm::operator=(const AForm &copy)
	{
		
	}

	std::string AForm::getName(void) const 
	{
		
	}
	
	bool AForm::isSigned(void) const
	{
		
	}
	
	int	AForm::getGradeSign(void) const
	{

	}
	
	int AForm::getGradeExec(void) const
	{
		
	}
	
	std::string AForm::getTarget(void) const
	{
		
	}
	
	void AForm::setTarget(std::string target)
	{
		
	}
	
	void AForm::beSigned(const Bureaucrat &b)
	{

	}
			
	void AForm::execute(Bureaucrat &b) const
	{

	}
