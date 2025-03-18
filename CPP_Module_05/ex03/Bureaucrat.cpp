/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:18:17 by manufern          #+#    #+#             */
/*   Updated: 2025/03/05 10:19:07 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Bureaucrat::Bureaucrat(): name("Default")
{
    std::cout << "Bureaucrat default constructor called for " << name << std::endl;
    this->grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name)
{
    std::cout << "Bureaucrat parameterized constructor called for " << name << std::endl;
    if(grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else if(grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade = grade;
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

std::string Bureaucrat::getName() const
{
    return(name);
}
int Bureaucrat::getGrade() const
{
    return(grade);
}
void Bureaucrat::incrementGrade()
{
    if (grade -1 < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else
    {
        grade --;
    }
}
void Bureaucrat::decrementGrade()
{
    if (grade + 1 > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else 
    {
        grade ++;
    }
}

const char* Bureaucrat::GradeTooHighException::what()  const  throw()
{
    return "Error: The grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const  throw()
{
    return "Error: The grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << "Name: " << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return os;
}

void Bureaucrat::signForm(AForm& form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}