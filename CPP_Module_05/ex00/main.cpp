/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:12:32 by manufern          #+#    #+#             */
/*   Updated: 2025/03/05 10:12:33 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
        std::cout << BOLD << CYAN << "Test for creating bureaucrats:" << RESET << std::endl << std::endl << std::endl;

        std::cout << YELLOW << "Creating a bureaucrat with a valid grade" << RESET << std::endl;
        Bureaucrat bureaucrat1("Juan", 50);
        std::cout << GREEN <<"Name: " << bureaucrat1.getName() << " grade: " << bureaucrat1.getGrade() << RESET << std::endl << std::endl << std::endl;

        std::cout << YELLOW << "Creating a bureaucrat with the lowest grade" << RESET << std::endl;
        Bureaucrat bureaucrat2("Luis", 150);
        std::cout << GREEN <<"Name: " << bureaucrat2.getName() << " grade: " << bureaucrat2.getGrade() << RESET << std::endl << std::endl << std::endl;

        std::cout << YELLOW << "Creating a bureaucrat with the highest grade" << RESET << std::endl;
        Bureaucrat bureaucrat3("Jose", 1);
        std::cout << GREEN <<"Name: " << bureaucrat3.getName() << " grade: " << bureaucrat3.getGrade() << RESET << std::endl << std::endl << std::endl;

        std::cout << RED << "Creating a bureaucrat with a grade higher than the maximum" << RESET << std::endl;
        Bureaucrat bureaucrat4("Desi", -1);
        std::cout << GREEN <<"Name: " << bureaucrat4.getName() << " grade: " << bureaucrat4.getGrade() << RESET << std::endl << std::endl << std::endl;
    }
    catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}

    try
    {
        std::cout << RED << "Creating a bureaucrat with a grade lower than the minimum" << RESET << std::endl;
        Bureaucrat bureaucrat5("Mark", 155);
        std::cout << GREEN <<"Name: " << bureaucrat5.getName() << " grade: " << bureaucrat5.getGrade() << RESET << std::endl << std::endl << std::endl;
    }
    catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}

    try
    {
        std::cout << std::endl << std::endl << std::endl << BOLD << CYAN << "Test for grade increment:" << RESET << std::endl << std::endl;

        std::cout << YELLOW << "Incrementing Juan's grade" << RESET << std::endl;
        Bureaucrat bureaucrat1("Juan", 50);
        std::cout << GREEN <<"Name: " << bureaucrat1.getName() << " grade: " << bureaucrat1.getGrade() << RESET << std::endl;
        bureaucrat1.incrementGrade();
        std::cout << GREEN <<"Name: " << bureaucrat1.getName() << " grade: " << bureaucrat1.getGrade() << RESET << std::endl;

        std::cout << YELLOW << "Incrementing Luis's grade" << RESET << std::endl;
        Bureaucrat bureaucrat2("Luis", 150);
        std::cout << GREEN <<"Name: " << bureaucrat2.getName() << " grade: " << bureaucrat2.getGrade() << RESET << std::endl;
        bureaucrat2.incrementGrade();
        std::cout << GREEN <<"Name: " << bureaucrat2.getName() << " grade: " << bureaucrat2.getGrade() << RESET << std::endl << std::endl << std::endl;
        
        std::cout << YELLOW << "Incrementing Jose's grade" << RESET << std::endl;
        Bureaucrat bureaucrat3("Jose", 1);
        std::cout << GREEN <<"Name: " << bureaucrat3.getName() << " grade: " << bureaucrat3.getGrade() << RESET << std::endl;
        bureaucrat3.incrementGrade();
        std::cout << GREEN <<"Name: " << bureaucrat3.getName() << " grade: " << bureaucrat3.getGrade() << RESET << std::endl << std::endl << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }

    try
    {
        std::cout << std::endl << std::endl << std::endl << BOLD << CYAN << "Test for grade decrement:" << RESET << std::endl << std::endl;

        std::cout << YELLOW << "Decrementing Juan's grade" << RESET << std::endl;
        Bureaucrat bureaucrat1("Juan", 50);
        std::cout << GREEN <<"Name: " << bureaucrat1.getName() << " grade: " << bureaucrat1.getGrade() << RESET << std::endl;
        bureaucrat1.decrementGrade();
        std::cout << GREEN <<"Name: " << bureaucrat1.getName() << " grade: " << bureaucrat1.getGrade() << RESET << std::endl << std::endl << std::endl;

        std::cout << YELLOW << "Decrementing Jose's grade" << RESET << std::endl;
        Bureaucrat bureaucrat3("Jose", 1);
        std::cout << GREEN <<"Name: " << bureaucrat3.getName() << " grade: " << bureaucrat3.getGrade() << RESET << std::endl;
        bureaucrat3.decrementGrade();
        std::cout << GREEN <<"Name: " << bureaucrat3.getName() << " grade: " << bureaucrat3.getGrade() << RESET << std::endl << std::endl << std::endl;

        std::cout << YELLOW << "Decrementing Luis's grade" << RESET << std::endl;
        Bureaucrat bureaucrat2("Luis", 150);
        std::cout << GREEN <<"Name: " << bureaucrat2.getName() << " grade: " << bureaucrat2.getGrade() << RESET << std::endl;
        bureaucrat2.decrementGrade();
        std::cout << GREEN <<"Name: " << bureaucrat2.getName() << " grade: " << bureaucrat2.getGrade() << RESET << std::endl << std::endl << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }
}