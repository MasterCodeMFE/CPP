/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:19:18 by manufern          #+#    #+#             */
/*   Updated: 2025/03/05 10:19:19 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

AForm* Intern::makeForm(std::string formName, std::string target)
{
    std::string validFrom[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    int iteratorNameForms = 0;
    while(iteratorNameForms < 3 && validFrom[iteratorNameForms] != formName)
    {
        iteratorNameForms ++;
    }
    AForm* Form = NULL;
    switch (iteratorNameForms)
    {
    case 0:
        std::cout << "Intern creates " << formName << std::endl;
        Form = new PresidentialPardonForm(target);
        break;
    case 1:
        std::cout << "Intern creates " << formName << std::endl;
        Form = new RobotomyRequestForm(target);
        break;
    case 2:
        std::cout << "Intern creates " << formName << std::endl;
        Form = new ShrubberyCreationForm(target);
        break;
    case 3:
        std::cout << "Error: Form name does not exist." << std::endl;
        break;
    }
    return (Form);
}