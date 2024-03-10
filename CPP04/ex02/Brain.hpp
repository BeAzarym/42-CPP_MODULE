/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:08:44 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/10 16:29:54 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
  private:
	std::string _ideas[100];

  public:
	Brain();
	Brain(const Brain &copy);
	~Brain();

	Brain &operator=(const Brain &copy);

	std::string getIdea(int index);
	void pushIdea(std::string idea);
	void replaceIdea(std::string idea, int index);
};

#endif