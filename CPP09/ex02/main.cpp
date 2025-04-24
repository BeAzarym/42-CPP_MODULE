/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:11:20 by cchabeau          #+#    #+#             */
/*   Updated: 2025/04/24 20:08:05 by cchabeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Invalid Argument" << std::endl;
		return -1;
	}

	struct timeval start, end;
	std::vector<int> vector, sorted_vector;
	std::list<int> list, sorted_list;	
	
	parseInput(argv, vector, list);

	std::cout << "BEFORE:	";
	printStack(vector);
	gettimeofday(&start, 0);
	sorted_vector = ProcessFordJohnsonSort(vector);
	gettimeofday(&end, 0);

	std::cout << "AFTER:	";
	printStack(sorted_vector);
	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << end.tv_usec - start.tv_usec << " us." << std::endl;

	gettimeofday(&start, 0);
	sorted_list = ProcessFordJohnsonSort(list);
	gettimeofday(&end, 0);
	std::cout << "Time to process a range of " << vector.size() << " elements with std::list : " << end.tv_usec - start.tv_usec << " us." << std::endl;

	gettimeofday(&start, 0);
	std::sort(vector.begin(), vector.end());
	gettimeofday(&end, 0);
    
	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector and std::sort : " << end.tv_usec - start.tv_usec << " us." << std::endl;



}