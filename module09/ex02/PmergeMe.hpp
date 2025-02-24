/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:11:35 by plang             #+#    #+#             */
/*   Updated: 2025/02/24 18:29:13 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <chrono>
# include <vector>
# include <deque>
# include <sstream>
# include <limits.h>
# include <algorithm>
# include <cmath>

class PmergeMe
{
	private:
		std::vector<int>	m_vector;
		std::vector<int>	m_sortedVector;
		std::deque<int>		m_deque;
		std::deque<int>		m_sortedDeque;

		PmergeMe();
		PmergeMe(const PmergeMe &);
		const PmergeMe&	operator=(const PmergeMe &);

	public:
		PmergeMe(int argc,char **argv);
		~PmergeMe();

		std::vector<int> &	getVector();
		std::vector<int>	getSortedVector();

		std::deque<int>	&	getDeque();
		std::deque<int>		getSortedDeque();

		void	sortVector(std::vector<int> &);
		void	jacobsthalInsertionVector(std::vector<int> &, std::vector<int> &);
};

#endif