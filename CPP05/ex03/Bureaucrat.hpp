/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:21:14 by cchabeau          #+#    #+#             */
/*   Updated: 2024/09/21 11:25:32 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "AForm.hpp"

# define RED "\033[31m"
# define GREY "\033[90m"
# define BOLD_BLUE "\033[1;34m"
# define RESET "\033[0m"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_gradeSign;
		int					_gradeExec;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, const int gradeSign, const int gradeExec);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat(void);

		Bureaucrat &operator=(const Bureaucrat &copy);

		std::string getName(void) const;
		int 		getGradeSign(void) const;
		int			getGradeExec(void) const;
		void 		incrementGrade(void);
		void 		decrementGrade(void);
		void 		signForm(AForm &form) const;
		void 		executeForm(const AForm &form);

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif