/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:20:29 by manufern          #+#    #+#             */
/*   Updated: 2025/03/05 10:20:30 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery", false, 145, 134), target(target)
{
    std::cout << "Shrubbery default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), target(other.target)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return(target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if(getIsSigned() == false)
    {
        std::cout << executor.getName() << " can not executed " << getName() << " because the form is not sign."<< std::endl;
        return;
    }
    if (executor.getGrade() > this->getGradeToExecute())
    {
        throw AForm::GradeTooLowExceptionExecurtor();
    }
    else
    {
        std::string filename = target + "_shrubbery";
        std::ofstream outFile(filename.c_str());
        if(!outFile)
        {
            std::cout << "Error: the file could not be created." << std::endl;
        }
        else
        {
            outFile << "                      ___\n"
            << "                _,-'\"\"   \"\"\"\"`--.\n"
            << "             ,-'          __,,-- \\\n"
            << "           ,'    __,--\"\"\"\"dF      )\n"
            << "          /   .-\"Hb_,--\"\"dF      /\n"
            << "        ,'       _Hb ___dF\"-._,-'\n"
            << "      ,'      _,-\"\"\"\"   \"\"--..__\n"
            << "     (     ,-'                  `.\n"
            << "      `._,'     _   _             ;\n"
            << "       ,'     ,' `-'Hb-.___..._,-'\n"
            << "       \\    ,\"'Hb.-'HH`-.dHF\"\n"
            << "        `--'   \"Hb  HH  dF\"\n"
            << "                \"Hb HH dF\n"
            << "                 \"HbHHdF\n"
            << "                  |HHHF\n"
            << "                  |HHH|\n"
            << "                  |HHH|\n"
            << "                  |HHH|\n"
            << "                  |HHH|\n"
            << "                  dHHHb\n"
            << "                .dFd|bHb.               o\n"
            << "      o       .dHFdH|HbTHb.          o /\n"
            << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y\n"
            << "##########################################\n";
        }
        outFile.close();
    }
}