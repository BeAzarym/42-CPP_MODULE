/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchabeau <cchabeau@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:11:20 by cchabeau          #+#    #+#             */
/*   Updated: 2025/04/17 22:32:56 by cchabeau         ###   ########.fr       */
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

	std::vector<int> vector, sorted_vector;
	std::list<int> list, sorted_list;	
	
	parseInput(argv, vector, list);

	std::cout << "BEFORE:	";
	printStack(vector);
	std::clock_t start = std::clock();
	sorted_vector = ProcessFordJohnsonSort(vector);
	std::clock_t end = std::clock();

	std::cout << "AFTER:	";
	printStack(sorted_vector);

	double elapse = (end - start) * 1000000.0 / CLOCKS_PER_SEC;
    
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " << elapse << " us." << std::endl;


	start = std::clock();
	sorted_list = ProcessFordJohnsonSort(list);
	end = std::clock();
	elapse = (end - start) * 1000000.0 / CLOCKS_PER_SEC;
    
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << vector.size() << " elements with std::list : " << elapse << " us." << std::endl;


	start = std::clock();
	std::sort(vector.begin(), vector.end());
	end = std::clock();
	elapse = (end - start) * 1000000.0 / CLOCKS_PER_SEC;
    
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector and std::sort : " << elapse << " us." << std::endl;



}