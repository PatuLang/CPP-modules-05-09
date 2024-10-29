/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:45:07 by plang             #+#    #+#             */
/*   Updated: 2024/10/29 11:49:35 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("blank"), isSigned(false), gradeToSign(1 + (rand()%(150 - 1 + 1))), gradeToExecute(1 + (rand()%(150 - 1 + 1)))
{
}

Form::Form(std::string _name, int _gradeToSign, int _gradeToExecute) : name(_name), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
{
	isSigned = false;
	if (gradeToSign > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1)
		throw GradeTooHighException();
	if (gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToExecute < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	isSigned = false;
	if (gradeToSign > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1)
		throw GradeTooHighException();
	if (gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToExecute < 1)
		throw GradeTooHighException();
}

Form&   Form::operator=(const Form &other)
{
	if (this != &other)
		isSigned = other.isSigned;
	return *this;
}

Form::~Form()
{
}

std::string	Form::getName() const
{
	return name;
}

bool	Form::getIsSigned() const
{
	return isSigned;
}

int	Form::getGradeToSign() const
{
	return gradeToSign;
}

int	Form::getGradeToExecute() const
{
	return gradeToExecute;
}

void	Form::beSigned(const Bureaucrat &requester)
{
	if (requester.getGrade() <= gradeToSign)
		isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream &out, Form &obj)
{
	return out << obj.getName() << ", isSigned: " << obj.getIsSigned() << ", gradeToSign: " << obj.getGradeToSign() << ", gradeToExecute: " << obj.getGradeToExecute();
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return "The grade is too high!";
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "The grade is too low!";
}
