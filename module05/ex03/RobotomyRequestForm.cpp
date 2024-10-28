/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:24:41 by plang             #+#    #+#             */
/*   Updated: 2024/10/28 13:48:02 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45)
{
	target = "basic";
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("RobotomyRequest", 72, 45), target(_target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		target = other.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() == false)
		throw FormNotSignedException();
	if (getGradeToExecute() < (executor.getGrade()))
		throw GradeTooLowException();
	std::cout << "Drill drill\n";
	srand(static_cast<unsigned int>(time(0)));
	if ((rand() % 2) == 1)
		std::cout << target << " has been robotomized\n";
	else
		std::cout << target << " robotomization has failed\n";
}
