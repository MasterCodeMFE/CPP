/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:31:54 by manuel            #+#    #+#             */
/*   Updated: 2025/01/20 16:37:58 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default"), grade(1)
{
    std::cout << "Bureaucrat default constructor called for " << name << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade): name(name), grade(grade)
{
    gradeOk(this->grade);
    std::cout << "Bureaucrat default constructor called for " << name << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat default destructor called for " << name << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade)
{
    std::cout << "Bureaucrat copy constructor called for " << name << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Bureaucrat assignment operator called for " << name << std::endl;
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << "Bureaucrat: " << bureaucrat.getName() << ", Grade: " << bureaucrat.getGrade();
    return os;
}

std::string Bureaucrat::getName()const
{
    return this->name;
}

int Bureaucrat::getGrade()const
{
    return this->grade;
}

void Bureaucrat::incrementGrade()
{
    gradeOk(this->grade - 1);
    this->grade --;
}

void Bureaucrat::decrementGrade()
{
    gradeOk(this->grade + 1);
    this->grade ++;
}

void Bureaucrat::gradeOk(int grade)
{
    if (grade > 150)
    {
        throw
            Bureaucrat::GradeTooLowException();
    }
    else if (grade < 1)
    {
        throw
            Bureaucrat::GradeTooHighException();
    }
}

const char* Bureaucrat::GradeTooLowException::what() const  throw()
{
    return "Error: The grade is too low";
}

const char* Bureaucrat::GradeTooHighException::what() const  throw()
{
    return "Error: The grade is too high";
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->name << " sign " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->name << " couldn’t sign " << form.getName() << " because ";
        std::cerr << e.what() << '\n';
    }
    
}