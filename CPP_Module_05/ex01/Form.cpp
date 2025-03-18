/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:13:33 by manufern          #+#    #+#             */
/*   Updated: 2025/03/05 10:13:34 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name("Default"), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, bool isSigned, int gradeToSign, int gradeToExecute): name(name), isSigned(isSigned), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout << "Form constructor called for " << name << std::endl;
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
    std::cout << "Form destructor called for " << name << std::endl;
}
Form::Form(const Form& other): name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "Form copy constructor called for " << name << std::endl;
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

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    os << "Form: " << obj.getName() << ", isSigned: " << obj.getIsSigned() << ", gradeToSign: " << obj.getGradeToSign() << ", gradeToExecute: " << obj.getGradeToExecute();
    return os;
}

const char* Form::GradeTooHighException::what()  const  throw()
{
    return "Error: The grade is too high";
}

const char* Form::GradeTooLowException::what() const  throw()
{
    return "Error: The grade is too low";
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
    {
        throw GradeTooLowException();
    }
    isSigned = true;
}