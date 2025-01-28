/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:22:30 by manufern          #+#    #+#             */
/*   Updated: 2024/12/18 17:52:23 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm(): name("default"), isSigned(1), gradeToSign(1), execGrade(1)
{
   std::cout << "Form constructor calls" << name << std::endl; 
}

AForm::AForm(const std::string name, int gradeToSign, const int execGrade): name(name), isSigned(false), gradeToSign(gradeToSign), execGrade(execGrade)
{
    std::cout << "Form constructor calls" << name << std::endl;
}

AForm::~AForm()
{
    std::cout << "Form destructor calls" << name << std::endl;
}

AForm::AForm(const AForm& other): name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), execGrade(other.execGrade)
{
     std::cout << "Form copy constructor called for " << name << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    std::cout << "Form assignment operator called for " << name << std::endl;
    if (this != &other)
    {
        this->isSigned = other.isSigned;
        this->gradeToSign = other.gradeToSign;
    }
    return *this;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Error: The grade is too high";
}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int  AForm::getGradeToSign() const
{
    return gradeToSign;
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Error: The grade is too low";
}
int AForm::getExecGrade() const
{
    return execGrade;
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
    out << "Form Name: " << form.getName() 
        << ", Is Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", Grade to Sign: " << form.getGradeToSign()
        << ", Execution Grade: " << form.getExecGrade();
    return out;
}

void AForm::beSigned(Bureaucrat bureaucrat)
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
