/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:22:30 by manufern          #+#    #+#             */
/*   Updated: 2024/12/18 16:24:46 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form(): name("default"), isSigned(1), gradeToSign(1), execGrade(1)
{
   std::cout << "Form constructor calls" << name << std::endl; 
}

Form::Form(const std::string name, int gradeToSign, const int execGrade): name(name), isSigned(false), gradeToSign(gradeToSign), execGrade(execGrade)
{
    std::cout << "Form constructor calls" << name << std::endl;
}

Form::~Form()
{
    std::cout << "Form destructor calls" << name << std::endl;
}

Form::Form(const Form& other): name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), execGrade(other.execGrade)
{
     std::cout << "Form copy constructor called for " << name << std::endl;
}

Form& Form::operator=(const Form& other)
{
    std::cout << "Form assignment operator called for " << name << std::endl;
    if (this != &other)
    {
        this->isSigned = other.isSigned;
        this->gradeToSign = other.gradeToSign;
    }
    return *this;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Error: The grade is too high";
}

std::string Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int  Form::getGradeToSign() const
{
    return gradeToSign;
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Error: The grade is too low";
}
int Form::getExecGrade() const
{
    return execGrade;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << "Form Name: " << form.getName() 
        << ", Is Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", Grade to Sign: " << form.getGradeToSign()
        << ", Execution Grade: " << form.getExecGrade();
    return out;
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
