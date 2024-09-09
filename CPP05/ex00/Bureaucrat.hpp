/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:21:14 by cchabeau          #+#    #+#             */
/*   Updated: 2024/08/25 23:34:33 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>

# define RED "\033[31m"
# define GREY "\033[90m"
# define BOLD_BLUE "\033[1;34m"
# define RESET "\033[0m"


class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat(void);

		Bureaucrat &operator=(const Bureaucrat &copy);

		std::string getName(void) const;
		int 		getGrade(void) const;
		void 		incrementGrade(void);
		void 		decrementGrade(void);


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