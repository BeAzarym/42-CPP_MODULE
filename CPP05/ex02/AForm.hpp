/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:41:09 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/12 17:02:27 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <string>
# include <iostream>

# define RED "\033[31m"
# define GREY "\033[90m"
# define BOLD_BLUE "\033[1;34m"
# define RESET "\033[0m"

class AForm
{
	private:
		const std::string			_name;
		std::string			_target;
		bool				_isSigned;
		const int 			_gradeSign;
		const int 			_gradeExec;
		
	public:
		AForm(void);
		AForm(const std::string name, const int gradeSign, const int gradeExec);
		AForm(const AForm &copy);
		~AForm();

		AForm &operator=(const AForm &copy);

		std::string		getName(void) const;
		bool			isSigned(void) const;
		int				getGradeSign(void) const;
		int				getGradeExec(void) const;
		std::string 	getTarget(void) const;
		void 			setTarget(std::string target);
		void 			beSigned(const Bureaucrat &b);
		virtual void	execute(Bureaucrat &b) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class IsAlreadySignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class IsNotSignedException: public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

		
#endif