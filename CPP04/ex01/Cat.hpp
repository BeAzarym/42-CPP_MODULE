/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:47:21 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/10 17:08:54 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
  private:
	Brain *_Brain;

  public:
	Cat();
	Cat(const Cat &copy);
	~Cat();

	Cat &operator=(const Cat &copy);

	virtual void makeSound() const;
	Brain *getBrain() const;
};
#endif