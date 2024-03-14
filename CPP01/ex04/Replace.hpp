/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:22:35 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/14 12:20:48 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <fstream>
# include <iostream>
# include <string>
# include <cstdlib>

class Replace
{
  private:
	std::fstream _Infile;
	std::fstream _Outfile;
	std::string _s1;
	std::string _s2;

	std::string Replaceline(void);

  public:
	Replace();
	Replace(std::string infile, std::string s1, std::string s2);
	~Replace();

	void Transform(void);
};

#endif