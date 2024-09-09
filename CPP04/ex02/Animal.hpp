/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:33:59 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/10 17:38:15 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
	protected:
		std::string _type;

	public:
		AAnimal();
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal();

		AAnimal &operator=(const AAnimal &copy);

		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif