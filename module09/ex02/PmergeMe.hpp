/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:11:35 by plang             #+#    #+#             */
/*   Updated: 2025/02/28 19:22:14 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <chrono>
# include <vector>
# include <deque>
# include <sstream>
# include <limits.h>
# include <algorithm>

class PmergeMe
{
	private:
		std::vector<int>	m_vector;
		std::deque<int>		m_deque;

		std::chrono::duration<double>	m_parseTime;
		
		std::chrono::time_point<std::chrono::high_resolution_clock>	m_vecStart;
		std::chrono::time_point<std::chrono::high_resolution_clock>	m_vecStop;
		std::chrono::time_point<std::chrono::high_resolution_clock>	m_deqStart;
		std::chrono::time_point<std::chrono::high_resolution_clock>	m_deqStop;

		PmergeMe();
		PmergeMe(const PmergeMe &);
		const PmergeMe&	operator=(const PmergeMe &);

	public:
		PmergeMe(int argc,char **argv);
		~PmergeMe();

		std::vector<int> &	getVector();
		std::deque<int>	&	getDeque();

		void	theVector();
		void	startVecTime();
		void	vecSort(std::vector<int> &);
		void	vecJacobsthalInsertion(std::vector<int> &, std::vector<int> &);
		void	vecPrintTruncated();
		void	vecPrint();

		void	theDeque();
		void	startDeqTime();
		void	deqSort(std::deque<int> &);
		void	deqJacobsthalInsertion(std::deque<int> &, std::deque<int> &);
		void	deqPrintTruncated();
		void	deqPrint();

		void	isItSorted();
};

#endif