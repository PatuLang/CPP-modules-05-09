/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:11:35 by plang             #+#    #+#             */
/*   Updated: 2025/02/03 13:48:39 by plang            ###   ########.fr       */
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

class PmergeMe
{
	private:
		std::vector<int>	m_vector;
		std::deque<int>		m_deque;

		PmergeMe();
		PmergeMe(const PmergeMe &);
		const PmergeMe&	operator=(const PmergeMe &);

	public:
		PmergeMe(int argc,char **argv);
		~PmergeMe();

		void	sortFordJohnson();
};

#endif