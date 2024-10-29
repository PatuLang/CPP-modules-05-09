/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:18:05 by plang             #+#    #+#             */
/*   Updated: 2024/10/29 09:14:30 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern&)
{
}

Intern& Intern::operator=(const Intern&)
{
	return *this;
}

Intern::~Intern()
{
}

AForm*	Intern::makeForm(std::string formName, std::string formTarget)
{
	AForm *newForm;
	std::string _forms[3] = {{"Robotomy request"}, {"Shrubbery creation"}, {"Presidential pardon"}};
	for(int i = 0; i < 3; i++)
	{
		if (formName == _forms[i])
		{
			switch (i)
			{
				case 0:
				{
					newForm = new RobotomyRequestForm(formTarget);
					std::cout << "Intern creates " << formName << "\n";
					break;
				}
				case 1:
				{
					newForm = new ShrubberyCreationForm(formTarget);
					std::cout << "Intern creates " << formName << "\n";
					break;
				}
				case 2:
				{
					newForm = new PresidentialPardonForm(formTarget);
					std::cout << "Intern creates " << formName << "\n";
					break;
				}
			}
			return newForm;
		}
	}
	throw FormDoesNotExistException();
}

const char* Intern::FormDoesNotExistException::what() const noexcept
{
	return "The requested form does not exist!";
}
