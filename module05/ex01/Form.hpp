/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:45:10 by plang             #+#    #+#             */
/*   Updated: 2024/10/25 11:33:14 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

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
		
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		void		beSigned(const Bureaucrat&);

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