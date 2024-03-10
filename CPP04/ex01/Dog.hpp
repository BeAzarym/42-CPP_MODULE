/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:53:58 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/10 17:09:03 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
  private:
	Brain *_Brain;

  public:
	Dog();
	Dog(const Dog &copy);
	~Dog();

	Dog &operator=(const Dog &copy);
	virtual void makeSound() const;
	Brain *getBrain() const;

};
#endif