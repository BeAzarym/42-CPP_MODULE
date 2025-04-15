/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:41:47 by cchabeau          #+#    #+#             */
/*   Updated: 2025/04/10 14:04:28 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <iostream>

int main()
{
	std::cout << "MUTANT >" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "LISTS >" << std::endl;
	std::list<int> lists;
	lists.push_back(5);
	lists.push_back(17);
	std::cout << lists.back() << std::endl;
	lists.pop_back();
	std::cout << lists.size() << std::endl;
	lists.push_back(3);
	lists.push_back(5);
	lists.push_back(737);
	//[...]
	lists.push_back(0);
	std::list<int>::iterator lit = lists.begin();
	std::list<int>::iterator lite = lists.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
	return 0;
}