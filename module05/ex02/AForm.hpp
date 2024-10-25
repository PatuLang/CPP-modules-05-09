/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:45:10 by plang             #+#    #+#             */
/*   Updated: 2024/10/25 11:12:59 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		std::string const	name;
		bool				isSigned;
		int const			gradeToSign;
		int const			gradeToExecute;
	public:
		AForm();
		AForm(std::string, int, int);
		AForm(const AForm&);
		AForm& operator=(const AForm&);
		virtual ~AForm();
		
		std::string		getName() const;
		bool			getIsSigned() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;
		virtual void	beSigned(const Bureaucrat&);
		virtual void	execute(Bureaucrat const &executor) const = 0;

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

	class FormNotSignedException : public std::exception
	{
		public:
			const char* what() const noexcept;
	};
};

std::ostream& operator<<(std::ostream&, AForm&);

#endif