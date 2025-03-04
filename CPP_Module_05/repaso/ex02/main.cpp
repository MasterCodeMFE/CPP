#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
    std::cout << BOLD << MAGENTA << "=== Testing ShrubberyCreationForm ===" << RESET << std::endl;

    try {
        std::cout << BOLD << GREEN << "Test no se puede firmar el formuliro." << RESET << std::endl;
        ShrubberyCreationForm form("HomeGarden1");
        Bureaucrat bureaucrat("LowRank", 150);

        std::cout << YELLOW << "Trying to sign form..." << RESET << std::endl;
        bureaucrat.signForm(form);
    } catch (const std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << BOLD << GREEN << "Test se puede firmar el formuliro." << RESET << std::endl;
        ShrubberyCreationForm form("HomeGarden2");
        Bureaucrat bureaucrat("MidRank", 145);

        std::cout << YELLOW << "Trying to sign form..." << RESET << std::endl;
        bureaucrat.signForm(form);
    } catch (const std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << BOLD << GREEN << "Test no se puede ejecutar el formulario por el grado es muy bajo." << RESET << std::endl;
        ShrubberyCreationForm form("HomeGarden3");
        Bureaucrat bureaucrat("HighRank", 139);

        std::cout << YELLOW << "Trying to sign form..." << RESET << std::endl;
        bureaucrat.signForm(form);

        std::cout << YELLOW << "Trying to execute form..." << RESET << std::endl;
        form.execute(bureaucrat);
    } catch (const std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << BOLD << GREEN << "Test no se puede ejecutar el formulario porque no esta firmado." << RESET << std::endl;
        ShrubberyCreationForm form("HomeGarden4");
        Bureaucrat bureaucrat("HigherRank", 17);

        std::cout << YELLOW << "Trying to execute form..." << RESET << std::endl;
        form.execute(bureaucrat);
    } catch (const std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << BOLD << GREEN << "Test se puede ejecutar el formulario." << RESET << std::endl;
        ShrubberyCreationForm form("HomeGarden5");
        Bureaucrat bureaucrat("HigherRank", 17);

        std::cout << YELLOW << "Trying to sign form..." << RESET << std::endl;
        bureaucrat.signForm(form);
        std::cout << YELLOW << "Trying to execute form..." << RESET << std::endl;
        form.execute(bureaucrat);
    } catch (const std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }


    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;


    std::cout << BOLD << MAGENTA << "=== Testing RobotomyRequestForm ===" << RESET << std::endl;
    try {
        std::cout << BOLD << GREEN << "Test no se puede firmar el formuliro." << RESET << std::endl;
        RobotomyRequestForm form("Robotomy1");
        Bureaucrat bureaucrat("LowRank", 150);

        std::cout << YELLOW << "Trying to sign form..." << RESET << std::endl;
        bureaucrat.signForm(form);
    } catch (const std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << BOLD << GREEN << "Test se puede firmar el formuliro." << RESET << std::endl;
        RobotomyRequestForm form("Robotomy2");
        Bureaucrat bureaucrat("MidRank", 72);

        std::cout << YELLOW << "Trying to sign form..." << RESET << std::endl;
        bureaucrat.signForm(form);
    } catch (const std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << BOLD << GREEN << "Test no se puede ejecutar el formulario por el grado es muy bajo." << RESET << std::endl;
        RobotomyRequestForm form("Robotomy3");
        Bureaucrat bureaucrat("HighRank", 72);

        std::cout << YELLOW << "Trying to sign form..." << RESET << std::endl;
        bureaucrat.signForm(form);

        std::cout << YELLOW << "Trying to execute form..." << RESET << std::endl;
        form.execute(bureaucrat);
    } catch (const std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << BOLD << GREEN << "Test no se puede ejecutar el formulario porque no esta firmado." << RESET << std::endl;
        RobotomyRequestForm form("Robotomy4");
        Bureaucrat bureaucrat("HigherRank", 17);

        std::cout << YELLOW << "Trying to execute form..." << RESET << std::endl;
        form.execute(bureaucrat);
    } catch (const std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << BOLD << GREEN << "Test se puede ejecutar el formulario." << RESET << std::endl;
        RobotomyRequestForm form("Robotomy5");
        Bureaucrat bureaucrat("HigherRank", 17);

        std::cout << YELLOW << "Trying to sign form..." << RESET << std::endl;
        bureaucrat.signForm(form);
        std::cout << YELLOW << "Trying to execute form..." << RESET << std::endl;
        form.execute(bureaucrat);
    } catch (const std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }    


    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;






    std::cout << BOLD << MAGENTA << "=== Testing PresidentialPardonForm ===" << RESET << std::endl;
    try {
        std::cout << BOLD << GREEN << "Test no se puede firmar el formuliro." << RESET << std::endl;
        PresidentialPardonForm form("Presidential1");
        Bureaucrat bureaucrat("LowRank", 150);

        std::cout << YELLOW << "Trying to sign form..." << RESET << std::endl;
        bureaucrat.signForm(form);
    } catch (const std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << BOLD << GREEN << "Test se puede firmar el formuliro." << RESET << std::endl;
        PresidentialPardonForm form("Presidential2");
        Bureaucrat bureaucrat("MidRank", 25);

        std::cout << YELLOW << "Trying to sign form..." << RESET << std::endl;
        bureaucrat.signForm(form);
    } catch (const std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << BOLD << GREEN << "Test no se puede ejecutar el formulario por el grado es muy bajo." << RESET << std::endl;
        PresidentialPardonForm form("Presidential3");
        Bureaucrat bureaucrat("HighRank", 25);

        std::cout << YELLOW << "Trying to sign form..." << RESET << std::endl;
        bureaucrat.signForm(form);

        std::cout << YELLOW << "Trying to execute form..." << RESET << std::endl;
        form.execute(bureaucrat);
    } catch (const std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << BOLD << GREEN << "Test no se puede ejecutar el formulario porque no esta firmado." << RESET << std::endl;
        PresidentialPardonForm form("Presidential4");
        Bureaucrat bureaucrat("HigherRank", 5);

        std::cout << YELLOW << "Trying to execute form..." << RESET << std::endl;
        form.execute(bureaucrat);
    } catch (const std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << BOLD << GREEN << "Test se puede ejecutar el formulario." << RESET << std::endl;
        PresidentialPardonForm form("Presidential5");
        Bureaucrat bureaucrat("HigherRank", 5);

        std::cout << YELLOW << "Trying to sign form..." << RESET << std::endl;
        bureaucrat.signForm(form);
        std::cout << YELLOW << "Trying to execute form..." << RESET << std::endl;
        form.execute(bureaucrat);
    } catch (const std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }    


    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;

    

    return 0;
}
