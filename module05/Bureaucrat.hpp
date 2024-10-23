/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:06:43 by plang             #+#    #+#             */
/*   Updated: 2024/10/23 15:46:39 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	private:
		std::string const	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string, int);
		Bureaucrat(const Bureaucrat&);
		Bureaucrat& operator=(const Bureaucrat&);
		~Bureaucrat();
		
		std::string	getName();
		int			getGrade();
		void		decrementGrade();
		void		incrementGrade();
	
	class GradeTooHighException : public std::exception
	{
		public:

	};

	class GradeTooLowException : public std::exception
	{
		public:
			
	};
};

std::ostream& operator<<(std::ostream&, Bureaucrat&);

#endif
