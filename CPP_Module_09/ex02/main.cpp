/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:30:39 by manufern          #+#    #+#             */
/*   Updated: 2025/04/02 17:12:31 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: you must provide at least one argument." << std::endl;
        return 1;
    }

    try
    {
        // Crear una instancia de PmergeMe que inicializa y almacena los números
        PmergeMe sorter(argc, argv);

        // Imprimir los números almacenados en vector y deque
        std::cout << "Numbers entered in vector: ";
        sorter.printHelper(sorter.getVector());

        std::cout << "Numbers entered in deque: ";
        sorter.printHelper(sorter.getDeque());

    }
    catch (const std::invalid_argument &e)
    {
        return 1; // Manejo de errores en los argumentos
    }

    return 0;
}