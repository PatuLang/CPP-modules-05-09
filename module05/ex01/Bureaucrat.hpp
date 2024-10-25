/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:06:43 by plang             #+#    #+#             */
/*   Updated: 2024/10/25 11:33:43 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Form;

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
		
		std::string	getName() const;
		int			getGrade() const;
		void		decrementGrade();
		void		incrementGrade();
		void		signForm(const Form&);
	
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const noexcept;
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const noexcept;
	};
};

std::ostream& operator<<(std::ostream&, Bureaucrat&);

#endif
