/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:33:48 by manufern          #+#    #+#             */
/*   Updated: 2025/01/21 12:48:42 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string const name, bool isSigned, int const gradeToSign, int const gradeToExecute): name(name), isSigned(isSigned), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout << "AForm default constructor called for " << name << std::endl;
    if (gradeToSign > 150 ||gradeToExecute > 150)
    {
        throw
            Bureaucrat::GradeTooLowException();
    }
    else if (gradeToSign < 1 ||gradeToExecute < 1)
    {
        throw
            Bureaucrat::GradeTooHighException();
    }
}

AForm::~AForm()
{
    std::cout << "AForm default destructor called for " << name << std::endl;
}

AForm::AForm(const AForm& other): name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "AForm copy constructor called for " << name << std::endl;
    if (gradeToSign > 150 ||gradeToExecute > 150)
    {
        throw
            Bureaucrat::GradeTooLowException();
    }
    else if (gradeToSign < 1 ||gradeToExecute < 1)
    {
        throw
            Bureaucrat::GradeTooHighException();
    }
}

AForm& AForm::operator=(const AForm& other)
{
    std::cout << "AForm assignment operator called for " << name << std::endl;
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

const char* AForm::GradeTooHighException::what() const  throw()
{
    return "Error: The grade is too high";
}

const char* AForm::GradeTooLowException::what() const  throw()
{
    return "Error: The grade is too low";
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
    os << "AForm: " << AForm.getName() << ", isSigned: " << AForm.getIsSigned() << ", gradeToSign: " << AForm.getGradeToSign() << ", gradeToExecute: " << AForm.getGradeToExecute();
    return os;
}

void AForm::beSigned(Bureaucrat bureaucrat)
{
    if (bureaucrat.getGrade() <= this->gradeToSign)
    {
        std::cout << "The bureaucrat " << bureaucrat.getName() << " is signing the AForm." << std::endl;
        this->isSigned = true;
    }
    else
    {
        throw GradeTooLowException();
    }
}