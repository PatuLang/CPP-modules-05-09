/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:24:46 by plang             #+#    #+#             */
/*   Updated: 2024/10/25 16:46:41 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137)
{
	target = "basic";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("ShrubberyCreation", 145, 137), target(_target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		target = other.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() == false)
		throw FormNotSignedException();
	if (getGradeToExecute() > executor.getGrade())
		throw GradeTooLowException();
}

