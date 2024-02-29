/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:08:13 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/01 00:44:13 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
  private:
	std::string _name;

  public:
	  Zombie(void);
	  Zombie(std::string name);
	  ~Zombie();

	  void announce();
	  void setName(std::string name);
};

#endif