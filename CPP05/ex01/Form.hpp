/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:29:00 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/26 11:22:58 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>

#define RED "\033[31m"
# define GREY "\033[90m"
# define BOLD_BLUE "\033[1;34m"
# define RESET "\033[0m"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_gradeSign;
		const int			_gradeExec;

	public:
		Form(void);
		Form(const std::string name, const int gradeSign, const int gradeExec);
		Form(const Form &copy);
		~Form(void);

		Form &operator=(const Form &copy);

		std::string	getName(void) const;
		bool		isSigned(void) const;
		int			getGradeSign(void) const;
		int			getGradeExec(void) const;
		void		beSigned(const Bureaucrat &b);

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
};

std::ostream &operator<<(std::ostream &out, const Form &form);


#endif