/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:06:25 by plang             #+#    #+#             */
/*   Updated: 2024/11/14 16:55:28 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("random")
{
	grade = 1 + (rand()%(150 - 1 + 1));
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name), grade(_grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
}

std::string	Bureaucrat::getName() const
{
	return name;
}

int	Bureaucrat::getGrade() const
{
	return grade;
}

void	Bureaucrat::incrementGrade()
{
	int	upgrade = grade - 1;
	if (upgrade < 1)
		throw GradeTooHighException();
	else
		grade -= 1;
}

void	Bureaucrat::decrementGrade()
{
	int	upgrade = grade + 1;
	if (upgrade > 150)
		throw GradeTooLowException();
	else
		grade += 1;
}

void	Bureaucrat::signForm(AForm &_form)
{
	_form.beSigned(*this);
	if (_form.getIsSigned() == true)
		std::cout << getName() << " signed " << _form.getName() << "\n";
	else
		std::cout << getName() << " couln't sign " << _form.getName() << " because the it isn't signed!" << "\n";
}

void	Bureaucrat::executeForm(AForm const &form)
{
	form.execute(*this);
	std::cout << getName() << " executed " << form.getName() << "\n";
}

std::ostream& operator<<(std::ostream &out, Bureaucrat &obj)
{
	return out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "The grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "The grade is too low!";
}
