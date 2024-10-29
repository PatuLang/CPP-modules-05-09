/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:18:21 by plang             #+#    #+#             */
/*   Updated: 2024/10/29 09:14:24 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Form;

class Intern
{
	private:

	public:
		Intern();
		Intern(const Intern&);
		Intern&	operator=(const Intern&);
		~Intern();
		
		AForm*	makeForm(std::string, std::string);

	class FormDoesNotExistException : public std::exception
	{
		public:
			const char* what() const noexcept;
	};
};

#endif