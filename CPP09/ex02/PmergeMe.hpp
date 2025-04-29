/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:10:46 by cchabeau          #+#    #+#             */
/*   Updated: 2025/04/29 13:53:34 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <sys/time.h>

void parseInput(char **argv, std::vector<int> &int_vector, std::list<int> &int_list);

class NotANumber : public std::exception
{
public:
	const char *what() const throw();
};

class NumberDuplicate : public std::exception
{
public:
	const char *what() const throw();
};

template <typename T>
void printStack(const T &input)
{
	for (typename T::const_iterator it = input.begin(); it != input.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename T>
T ProcessFordJohnsonSort(const T &input)
{
	if (input.size() < 1)
		return input;

	T small, large;

	for (typename T::const_iterator it = input.begin(); it != input.end();)
	{
		typename T::const_iterator next = it;
		++next;
		if (next == input.end())
		{
			small.push_back(*it);
			break;
		}
		if (*it > *next)
		{
			large.push_back(*it);
			small.push_back(*next);
		}
		else
		{
			large.push_back(*next);
			small.push_back(*it);
		}
		it = ++next;
	}

	large = ProcessFordJohnsonSort(large);


	std::vector<int> res;
	int j0, j1, next;

	j0 = 0;
	j1 = 1;
	while (j1 < static_cast<int>(small.size()))
	{
		if (res.empty() || res.back() != j1)
			res.push_back(j1);
		next = j1 + 2 * j0;
		j0 = j1;
		j1 = next;
	}
	std::vector<int> jacobsthalIndice = res;
	for (int i = 0; i < static_cast<int>(small.size()); ++i)
	{
		if (std::find(jacobsthalIndice.begin(), jacobsthalIndice.end(), i) == jacobsthalIndice.end())
			jacobsthalIndice.push_back(i);
	}

	for (size_t i = 0; i < jacobsthalIndice.size(); ++i)
	{
		int pos = jacobsthalIndice[i];
		typename T::const_iterator small_iterator = small.begin();
		std::advance(small_iterator, pos);
		int value = *small_iterator;
		typename T::iterator insertPos = std::lower_bound(large.begin(), large.end(), value);
		large.insert(insertPos, value);
	}
	return large;
}

#endif