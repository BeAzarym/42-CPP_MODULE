/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:13:59 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/07 20:19:57 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal
{
  protected:
	std::string _type;

  public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);
	~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal &copy);

	std::string getType() const;
	void makeSound() const;
};

#endif