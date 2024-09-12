/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:35:39 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/12 17:02:37 by cchabeau         ###   ########.fr       */
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
		if (this = &copy)
			return *this
		std::cout << GREY << "AForm Assignement operator called for " << this->getName() << RESET << std::endl;
		this->_name = copy._name;
		this->_isSigned = copy._isSigned;
		this->_target = copy._target;
	}

	std::string AForm::getName(void) const 
	{
		return (this->_name);
	}
	
	bool AForm::isSigned(void) const
	{
		return (this->_isSigned);
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
		this->_isSigned = true;
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

	const char *Aform::IsNotSignedException::what() const throw()
	{
		return ("Error: Form is not signed.");
	}

	std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	return (out << form.getName() << ", is signed: " << form.isSigned() << " need " << form.getGradeSign() << " to sign and need " << form.getGradeExec() << " to execute.");
}
