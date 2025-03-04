
#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Bureaucrat default destructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}