/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:55:33 by plang             #+#    #+#             */
/*   Updated: 2024/11/15 16:52:28 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <deque>

template<typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T>
{
	private:
	public:
		MutantStack();
		MutantStack(const MutantStack&);
		MutantStack& operator=(const MutantStack&);
		~MutantStack();

		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
		
		iterator begin(); // { return std::stack<T, Container>::c.begin(); };
		iterator end(); // { return std::stack<T, Container>::c.end(); };
		const_iterator begin() const;// { return std::stack<T, Container>::c.begin(); };
		const_iterator end() const;// { return std::stack<T, Container>::c.end(); };
};

# include "MutantStack.tpp"

#endif