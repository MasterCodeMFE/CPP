/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:31:29 by manuel            #+#    #+#             */
/*   Updated: 2025/01/21 12:53:34 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp" // Asegúrate de incluir el encabezado de Bureaucrat

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int main()
{
    try
    {
        std::cout << BOLD << CYAN << "Test for creating forms:" << RESET << std::endl << std::endl;

        std::cout << YELLOW << "Creating a form with valid grades" << RESET << std::endl;
        AForm form1("Form1", false, 50, 75);
        std::cout << GREEN << "Form Name: " << form1.getName() << ", Is Signed: " << form1.getIsSigned() 
                  << ", Grade to Sign: " << form1.getGradeToSign() << ", Grade to Execute: " 
                  << form1.getGradeToExecute() << RESET << std::endl << std::endl;

        std::cout << YELLOW << "Creating a form with a high grade to sign" << RESET << std::endl;
        AForm form2("Form2", false, 1, 50);
        std::cout << GREEN << "Form Name: " << form2.getName() << ", Is Signed: " << form2.getIsSigned() 
                  << ", Grade to Sign: " << form2.getGradeToSign() << ", Grade to Execute: " 
                  << form2.getGradeToExecute() << RESET << std::endl << std::endl;

        std::cout << YELLOW << "Creating a form with a low grade to execute" << RESET << std::endl;
        AForm form3("Form3", false, 100, 151);
        std::cout << GREEN << "Form Name: " << form3.getName() << ", Is Signed: " << form3.getIsSigned() 
                  << ", Grade to Sign: " << form3.getGradeToSign() << ", Grade to Execute: " 
                  << form3.getGradeToExecute() << RESET << std::endl << std::endl;

        std::cout << RED << "Creating a form with a grade too high to sign" << RESET << std::endl;
        AForm form4("Form4", false, -1, 50);
        std::cout << GREEN << "Form Name: " << form4.getName() << ", Is Signed: " << form4.getIsSigned() 
                  << ", Grade to Sign: " << form4.getGradeToSign() << ", Grade to Execute: " 
                  << form4.getGradeToExecute() << RESET << std::endl << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }

    try
    {
        std::cout << RED << "Creating a form with a grade too low to execute" << RESET << std::endl;
        AForm form5("Form5", false, 150, 160);
        std::cout << GREEN << "Form Name: " << form5.getName() << ", Is Signed: " << form5.getIsSigned() 
                  << ", Grade to Sign: " << form5.getGradeToSign() << ", Grade to Execute: " 
                  << form5.getGradeToExecute() << RESET << std::endl << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }

    try
    {
        std::cout << std::endl << BOLD << CYAN << "Test for signing forms:" << RESET << std::endl << std::endl;

        Bureaucrat bureaucrat1("Juan", 50);
        AForm form6("Form6", false, 50, 75);
        std::cout << YELLOW << "Signing form with bureaucrat:" << RESET << std::endl;
        bureaucrat1.signForm(form6);
        std::cout << GREEN << form6 << RESET << std::endl;

        Bureaucrat bureaucrat2("Luis", 30);
        AForm form7("Form7", false, 40, 75);
        std::cout << YELLOW << "Signing form with bureaucrat:" << RESET << std::endl;
        bureaucrat2.signForm(form7);
        std::cout << GREEN << form7 << RESET << std::endl;

        Bureaucrat bureaucrat3("Jose", 100);
        AForm form8("Form8", false, 50, 75);
        std::cout << YELLOW << "Trying to sign form with bureaucrat with too low grade:" << RESET << std::endl;
        bureaucrat3.signForm(form8);
        std::cout << GREEN << form8 << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }

    return 0;
}