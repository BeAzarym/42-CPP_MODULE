/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:35:39 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/21 11:12:48 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

	AForm::AForm(void): _name("Default"), _gradeSign(1), _gradeExec(1), _target("Default"), _isSign(false) 
	{
		std::cout << GREY << "AForm Default constructor called" << RESET << std::endl;
	}

	AForm::AForm(const std::string name, const int gradeSign, const int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _target("Default"), _isSign(false)
	{
		std::cout << GREY << "AForm Assignement constructor called for " << this->getName() << RESET << std::endl;
		if (gradeSign < 1 || gradeExec < 1)
			throw GradeTooHighException();
		if (gradeSign > 150 || gradeExec > 150)
			throw GradeTooLowException();
	}

	AForm::AForm(const AForm &copy) : _name(copy._name), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec), _target(copy._target), _isSign(false)
	{
		std::cout << GREY << "AForm Copy Assignement constructor called for " << this->getName() << RESET << std::endl;
	}

	AForm::~AForm()

	{
		std::cout << GREY << "AForm Destructor called for " << this->getName() << RESET << std::endl;
	}

	AForm &AForm::operator=(const AForm &copy)
	{
		if (this == &copy)
			return *this;
		std::cout << GREY << "AForm Assignement operator called for " << this->getName() << RESET << std::endl;
		this->_isSign = copy._isSign;
		this->_target = copy._target;
		return *this;
	}

	std::string AForm::getName(void) const 
	{
		return (this->_name);
	}
	
	bool AForm::isSigned(void) const
	{
		return (this->_isSign);
	}
	
	int	AForm::getGradeSign(void) const
	{
		return (this->_gradeSign);
	}
	
	int AForm::getGradeExec(void) const
	{
		return (this->_gradeExec);
	}
	
	std::string AForm::getTarget(void) const
	{
		return (this->_target);
	}
	
	void AForm::setTarget(std::string target)
	{
		this->_target = target;
	}
	
	void AForm::beSigned(const Bureaucrat &b)
	{
		if (this->isSigned())
			throw(AForm::IsAlreadySignedException());
		if (this->getGradeSign() < b.getGradeSign())
			throw(AForm::GradeTooLowException());
		this->_isSign = true;
	}

	const char *AForm::GradeTooHighException::what() const throw()
	{
		return ("Error: Grade is too high.");
	}

	const char *AForm::GradeTooLowException::what() const throw()
	{
		return ("Error: Grade is too low.");
	}

	const char *AForm::IsAlreadySignedException::what() const throw()
	{
		return ("Error: Form is already signed.");
	}

	const char *AForm::IsNotSignedException::what() const throw()
	{
		return ("Error: Form is not signed.");
	}

	std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	return (out << form.getName() << ", is signed: " << form.isSigned() << " need " << form.getGradeSign() << " to sign and need " << form.getGradeExec() << " to execute.");
}
