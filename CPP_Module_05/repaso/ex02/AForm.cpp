
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm::AForm(): name("Default"), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
    std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExecute): name(name), isSigned(isSigned), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
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

AForm::~AForm()
{
    std::cout << "Form destructor called for " << name << std::endl;
}
AForm::AForm(const AForm& other): name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "Form copy constructor called for " << name << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    std::cout << "Form assignment operator called for " << name << std::endl;
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

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
    os << "Form: " << obj.getName() << ", isSigned: " << obj.getIsSigned() << ", gradeToSign: " << obj.getGradeToSign() << ", gradeToExecute: " << obj.getGradeToExecute();
    return os;
}

const char* AForm::GradeTooHighException::what()  const  throw()
{
    return "Error: The grade is too high";
}

const char* AForm::GradeTooLowException::what() const  throw()
{
    return "Error: The grade is too low";
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
    {
        throw GradeTooLowException();
    }
    isSigned = true;
}

const char* AForm::GradeTooLowExceptionExecurtor::what()  const  throw()
{
    return "Error: The grade is too low to execute";
}

const char* AForm::GradeTooLowExceptionSign::what()  const  throw()
{
    return "Error: The grade is too low to sign";
}