/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:04:52 by manufern          #+#    #+#             */
/*   Updated: 2024/12/18 13:05:41 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "******** TEST CREACIÓN ********\n" << std::endl;
    try
    {
        Bureaucrat boss("David", 1);
        std::cout << boss << std::endl;

        Bureaucrat intern("Gema", 150);
        std::cout << intern << std::endl;

        Bureaucrat mid("Nico", 75);
        std::cout << mid << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n******** TEST INCREMENTOS ********\n" << std::endl;
    try
    {
        Bureaucrat top("Irene", 0);
        std::cout << top << std::endl;

        top.setIncrement();
        std::cout << "After increment: " << top << std::endl;

        // Esto lanzará una excepción
        top.setIncrement();
        std::cout << "After second increment: " << top << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n******** TEST DECREMENTOS ********\n" << std::endl;
    try
    {
        Bureaucrat bottom("Ferran", 149);
        std::cout << bottom << std::endl;

        bottom.setDecrement();
        std::cout << "After decrement: " << bottom << std::endl;

        // Esto lanzará una excepción
        bottom.setDecrement();
        std::cout << "After second decrement: " << bottom << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n******** TEST VALORES INVÁLIDOS ********\n" << std::endl;
    try
    {
        Bureaucrat invalidHigh("Ruben", 0); // Grade demasiado alto
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat invalidLow("Antonio", 200); // Grade demasiado bajo
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n******** TEST COPIA Y ASIGNACIÓN ********\n" << std::endl;
    try
    {
        Bureaucrat original("Manuel", 42);
        std::cout << "Original: " << original << std::endl;

        Bureaucrat copy = original; // Constructor de copia
        std::cout << "Copy: " << copy << std::endl;

        Bureaucrat assigned("Luis", 100);
        assigned = original; // Operador de asignación
        std::cout << "Assigned: " << assigned << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n******** FIN DEL TEST ********\n" << std::endl;

    return 0;
}