/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:45:19 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/04 21:29:34 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int _FixedNum;
		static const int fractionnal_bit = 8;

	public:
		Fixed();
		Fixed(const float n);
		Fixed(const int n);
		Fixed(const Fixed &f);
		~Fixed();

		Fixed &operator=(const Fixed &f);

		int getRawBits(void) const;
		void setRawBit(int n);
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif