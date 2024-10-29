/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:45:07 by plang             #+#    #+#             */
/*   Updated: 2024/10/25 11:13:17 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("blank"), isSigned(false), gradeToSign(1 + (rand()%(150 - 1 + 1))), gradeToExecute(1 + (rand()%(150 - 1 + 1)))
{
}

AForm::AForm(std::string _name, int _gradeToSign, int _gradeToExecute) : name(_name), gradeToSign(_gradeToSign), gradeToExecute(_gradeToExecute)
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

AForm::AForm(const AForm &other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
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

AForm&   AForm::operator=(const AForm &other)
{
	if (this != &other)
		isSigned = other.isSigned;
	return *this;
}

AForm::~AForm()
{
}

std::string	AForm::getName() const
{
	return name;
}

bool	AForm::getIsSigned() const
{
	return isSigned;
}

int	AForm::getGradeToSign() const
{
	return gradeToSign;
}

int	AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

void	AForm::beSigned(const Bureaucrat &requester)
{
	if (requester.getGrade() <= gradeToSign)
		isSigned = true;
	else
		throw GradeTooLowException();
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() == false)
		throw FormNotSignedException();
	if (getGradeToExecute() < executor.getGrade())
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream &out, AForm &obj)
{
	return out << obj.getName() << ", isSigned: " << obj.getIsSigned() << ", gradeToSign: " << obj.getGradeToSign() << ", gradeToExecute: " << obj.getGradeToExecute();
}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return "The grade is too high!";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return "The grade is too low!";
}

const char* AForm::FormNotSignedException::what() const noexcept
{
	return "The form is not signed!";
}
