/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:33:48 by manufern          #+#    #+#             */
/*   Updated: 2025/01/20 16:45:21 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const name, bool isSigned, int const gradeToSign, int const gradeToExecute): name(name), isSigned(isSigned), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout << "Form default constructor called for " << name << std::endl;
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

Form::~Form()
{
    std::cout << "Form default destructor called for " << name << std::endl;
}

Form::Form(const Form& other): name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "Form copy constructor called for " << name << std::endl;
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

Form& Form::operator=(const Form& other)
{
    std::cout << "Form assignment operator called for " << name << std::endl;
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

std::string Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

const char* Form::GradeTooHighException::what() const  throw()
{
    return "Error: The grade is too high";
}

const char* Form::GradeTooLowException::what() const  throw()
{
    return "Error: The grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& Form)
{
    os << "Form: " << Form.getName() << ", isSigned: " << Form.getIsSigned() << ", gradeToSign: " << Form.getGradeToSign() << ", gradeToExecute: " << Form.getGradeToExecute();
    return os;
}

void Form::beSigned(Bureaucrat bureaucrat)
{
    if (bureaucrat.getGrade() <= this->gradeToSign)
    {
        std::cout << "The bureaucrat " << bureaucrat.getName() << " is signing the form." << std::endl;
        this->isSigned = true;
    }
    else
    {
        throw GradeTooLowException();
    }
}