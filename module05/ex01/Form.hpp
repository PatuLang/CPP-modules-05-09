/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:45:10 by plang             #+#    #+#             */
/*   Updated: 2024/10/24 16:56:01 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	name;
		bool				isSigned;
		int const			gradeToSign;
		int const			gradeToExecute;
	public:
		Form();
		Form(std::string, int, int);
		Form(const Form&);
		Form& operator=(const Form&);
		~Form();
		
		std::string	getName();
		bool		getIsSigned();
		int			getGradeToSign();
		int			getGradeToExecute();
		void		beSigned(Bureaucrat&);
		void		signForm(Bureaucrat&);

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

std::ostream& operator<<(std::ostream&, Form&);

#endif