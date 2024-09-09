/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:29:03 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/26 11:29:21 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("Default"), _is_signed(false), _gradeSign(150), _gradeExec(150)
{
	std::cout << GREY << "[Form] Default Constructor called" << RESET << std::endl;
}

Form::Form(const std::string name, const int gradeSign, const int gradeExec) : _name(name), _is_signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	std::cout << GREY << "[Form] Assignement Constructor called for " << name << RESET << std::endl;
	if (gradeSign < 1 || gradeExec < 1)
		throw(Form::GradeTooHighException());
	if (gradeSign > 150 || gradeExec > 150)
		throw(Form::GradeTooLowException());
}

Form::Form(const Form &copy) : _name(copy._name), _is_signed(copy._is_signed), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec)
{
	std::cout << GREY << "[Form] Copy Constructor called for " << copy.getName() << RESET << std::endl;
}

Form::~Form(void)
{
	std::cout << GREY << "[Form] Destructor called for " << this->getName() << RESET << std::endl;	
}

Form &Form::operator=(const Form &copy)
{
	if (this == &copy)
		return (*this);
	std::cout << GREY << "[Form] Assignement Operator called for " << this->getName() << RESET << std::endl;
	this->_is_signed = copy._is_signed;
	return (*this);
}

std::string Form::getName(void) const
{
	return (this->_name);
}

bool Form::isSigned(void) const
{
	return (this->_is_signed);
}

int Form::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int Form::getGradeExec(void) const
{
	return (this->_gradeExec);
}

void Form::beSigned(const Bureaucrat &b)
{
	if (this->isSigned())
		throw(Form::IsAlreadySignedException());
	if (this->getGradeSign() < b.getGrade())
		throw(Form::GradeTooLowException());
	this->_is_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Error: Grade is too high to sign or execute this form.");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Error: Grade is too low to sign or exectute this form.");
}

const char *Form::IsAlreadySignedException::what() const throw()
{
	return ("Error: Form is already signed.");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	return (out << form.getName() << ", is signed: " << form.isSigned() << " need " << form.getGradeSign() << " to sign and need " << form.getGradeExec() << " to execute.");
}
