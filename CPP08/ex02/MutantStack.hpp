/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:43:19 by cchabeau          #+#    #+#             */
/*   Updated: 2025/04/10 13:58:59 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>() : std::stack<T>(){};
		MutantStack<T>(const MutantStack &other) : std::stack<T>(other){};
		~MutantStack<T>(){};

		MutantStack<T> &operator=(const MutantStack &other)
		{
			std::stack<T>::operator=(other);
			return (*this);
		}

		typedef typename MutantStack<T>::stack::container_type::iterator iterator;
		typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
		typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
		typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin() { return this->c.begin(); }
		
		iterator end() { return this->c.end(); }
		
		reverse_iterator rbegin() { return this->c.rbegin(); }
		
		reverse_iterator rend() { return this->c.rend(); }
		
		const_iterator begin() const { return this->c.begin(); }
		
		const_iterator end() const { return this->c.end(); }
		
		const_reverse_iterator rbegin() const { return this->c.rbegin(); }
		
		const_reverse_iterator rend() const { return this->c.rend(); }
		
};

#endif