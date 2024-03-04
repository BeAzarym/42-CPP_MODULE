/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:45:19 by cchabeau          #+#    #+#             */
/*   Updated: 2024/03/04 22:17:03 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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

	bool operator>(const Fixed &f) const;
	bool operator<(const Fixed &f) const;
	bool operator>=(const Fixed &f) const;
	bool operator<=(const Fixed &f) const;
	bool operator==(const Fixed &f) const;
	bool operator!=(const Fixed &f) const;

	Fixed operator+(const Fixed &f) const;
	Fixed operator-(const Fixed &f) const;
	Fixed operator*(const Fixed &f) const;
	Fixed operator/(const Fixed &f) const;

	Fixed operator++(int);
	Fixed &operator++();
	Fixed operator--(int);
	Fixed &operator--(void);

	static Fixed &min(Fixed &f1, Fixed &f2);
	static const Fixed &min(Fixed const &f1, Fixed const &f2);
	static Fixed &max(Fixed &f1, Fixed &f2);
	static const Fixed &max(Fixed const &f1, Fixed const &f2);

	int getRawBits(void) const;
	void setRawBit(int n);

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixed);

#endif