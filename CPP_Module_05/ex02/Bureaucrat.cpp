#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default"), grade(1) 
{
    std::cout << "Bureaucrat default constructor called for " << name << std::endl;
}
Bureaucrat::~Bureaucrat() 
{
    std::cout << "Bureaucrat destructor called for " << name << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(grade)
{
    std::cout << "Bureaucrat parameterized constructor called for " << name << std::endl;
    if (this->grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (this->grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
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

const std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::setIncrement()
{
    if (this->grade - 1 < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade--;
}

void Bureaucrat::setDecrement()
{
    if (this->grade + 1 > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Error: The grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Error: The grade is too low";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}

void Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->name << " sign " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->name << " couldn’t sign " << form.getName() << " because ";
        std::cerr << e.what() << std::endl;
    }
    
}