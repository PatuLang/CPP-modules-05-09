/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:06:25 by plang             #+#    #+#             */
/*   Updated: 2024/10/23 17:09:56 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("random")
{
	grade = 1 + (rand()%(150 - 1 + 1));
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name), grade(_grade)
{
	
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{

}

Bureaucrat&   Bureaucrat::operator=(const Bureaucrat &other)
{

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

}

void	Bureaucrat::incrementGrade()
{

}

std::ostream& operator<<(std::ostream &out, Bureaucrat &obj)
{
	return out << obj.getName() << ", bureaucrat grade " << obj.getName();
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{

}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	
}
