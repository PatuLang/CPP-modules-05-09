/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:24:34 by plang             #+#    #+#             */
/*   Updated: 2024/10/25 16:47:42 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5)
{
	target = "basic";
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("PresidentialPardon", 25, 5), target(_target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target(other.target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		target = other.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() == false)
		throw FormNotSignedException();
	if (getGradeToExecute() > executor.getGrade())
		throw GradeTooLowException();
}
	