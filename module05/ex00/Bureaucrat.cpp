/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:06:25 by plang             #+#    #+#             */
/*   Updated: 2024/10/24 14:41:02 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("random")
{
	grade = 1 + (rand()%(150 - 1 + 1));
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name), grade(_grade)
{
	if (grade > 150)
		throw GradeTooHighException();
	if (grade < 1)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
	if (grade > 150)
		throw GradeTooHighException();
	if (grade < 1)
		throw GradeTooLowException();
}

Bureaucrat&   Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string	Bureaucrat::getName()
{
	return name;
}

int	Bureaucrat::getGrade()
{
	return grade;
}

void	Bureaucrat::decrementGrade()
{
	int	upgrade = grade - 1;
	if (upgrade < 1)
		throw GradeTooLowException();
	else
		grade -= 1;
}

void	Bureaucrat::incrementGrade()
{
	int	upgrade = grade + 1;
	if (upgrade > 150)
		throw GradeTooHighException();
	else
		grade += 1;
}

std::ostream& operator<<(std::ostream &out, Bureaucrat &obj)
{
	return out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "The grade is too high, 150 is the highest grade!";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "The grade is too low, 1 is the lowest grade!";
}
