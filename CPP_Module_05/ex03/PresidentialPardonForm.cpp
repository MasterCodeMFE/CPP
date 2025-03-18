/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:19:51 by manufern          #+#    #+#             */
/*   Updated: 2025/03/05 10:19:52 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential", false, 25, 5), target(target)
{
    std::cout << "Presidential default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Presidential default destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), target(other.target)
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        target=other.target;
    }
    return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
    return(target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if(getIsSigned() == false)
    {
        std::cout << executor.getName() << " can not executed " << getName() << " because the form is not sign." << std::endl;
        return;
    }
    if (executor.getGrade() > this->getGradeToExecute())
    {
        throw AForm::GradeTooLowExceptionExecurtor();
    }
    std::cout << executor.getName() << " executed " << getName() << std::endl;
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}