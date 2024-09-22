/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:12:46 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/22 15:30:09 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	this->setTarget("Default");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("RobotomyRequestForm", 72, 45)
{
	this->setTarget(copy.getTarget());
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this == &copy)
		return (*this);
	this->setTarget(copy.getTarget());
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat &executor) const
{
	if (!this->isSigned())
		throw(IsNotSignedException());
	if (this->getGradeExec() < executor.getGradeExec())
		throw(GradeTooLowException());

	std::cout << "ZZZzzzzzzZZZZZ *Drilling Noise*" << std::endl;
	
	std::srand(std::time(NULL));
	if (std::rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->getTarget() << " has failled his robotomized." << std::endl;
}