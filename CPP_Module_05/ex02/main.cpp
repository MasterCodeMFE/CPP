/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:04:52 by manufern          #+#    #+#             */
/*   Updated: 2024/12/18 17:53:12 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int main() {
    try {
        std::cout << CYAN << "Creando objetos Bureaucrat y Form..." << RESET << std::endl;
        Bureaucrat bob("Bob", 50);
        AForm form1("Form 1", 40, 100);
        AForm form2("Form 2", 60, 100);

        // Imprimir información de los formularios
        std::cout << BLUE << "Imprimiendo información inicial de los formularios:" << RESET << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

        // Intentar firmar formularios
        std::cout << GREEN << "Intentando firmar Form 1..." << RESET << std::endl;
        bob.signForm(form1); // Debería firmar
        std::cout << GREEN << "Intentando firmar Form 2..." << RESET << std::endl;
        bob.signForm(form2); // No debería firmar

        // Imprimir información de los formularios después de la firma
        std::cout << BLUE << "Imprimiendo información final de los formularios:" << RESET << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

    } catch (const std::exception& e) {
        std::cerr << RED << "Se lanzó una excepción: " << e.what() << RESET << std::endl;
    }

    return 0;
}