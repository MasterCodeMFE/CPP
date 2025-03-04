#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

// Colores ANSI
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"

int main()
{
    Intern intern;

    std::cout << CYAN << "==== TEST CASES ====" << RESET << std::endl;

    // Casos válidos
    std::cout << BLUE << "\n[TEST] Creating PresidentialPardonForm" << RESET << std::endl;
    AForm* form1 = intern.makeForm("presidential pardon", "Target1");
    if (form1)
        std::cout << GREEN << "✔ Form created successfully!\n" << RESET;

    std::cout << BLUE << "\n[TEST] Creating RobotomyRequestForm" << RESET << std::endl;
    AForm* form2 = intern.makeForm("robotomy request", "Target2");
    if (form2)
        std::cout << GREEN << "✔ Form created successfully!\n" << RESET;

    std::cout << BLUE << "\n[TEST] Creating ShrubberyCreationForm" << RESET << std::endl;
    AForm* form3 = intern.makeForm("shrubbery creation", "Target3");
    if (form3)
        std::cout << GREEN << "✔ Form created successfully!\n" << RESET;

    // Casos inválidos
    std::cout << RED << "\n[TEST] Trying to create an unknown form (Should fail)" << RESET << std::endl;
    AForm* form4 = intern.makeForm("UnknownForm", "Target4");
    if (!form4)
        std::cout << RED << "✖ Form creation failed as expected.\n" << RESET;

    std::cout << RED << "\n[TEST] Trying to create an empty form name (Should fail)" << RESET << std::endl;
    AForm* form5 = intern.makeForm("", "Target5");
    if (!form5)
        std::cout << RED << "✖ Form creation failed as expected.\n" << RESET;

    std::cout << RED << "\n[TEST] Trying to create a random text form (Should fail)" << RESET << std::endl;
    AForm* form6 = intern.makeForm("random text", "Target6");
    if (!form6)
        std::cout << RED << "✖ Form creation failed as expected.\n" << RESET;

    // Liberar memoria
    delete form1;
    delete form2;
    delete form3;
    delete form4;
    delete form5;
    delete form6;
    
    
    
    /* Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender"); */

    return 0;
}
