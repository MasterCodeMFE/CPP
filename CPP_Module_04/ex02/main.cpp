/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:22:33 by manufern          #+#    #+#             */
/*   Updated: 2024/12/16 11:14:11 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
    // Introducción visual
    std::cout << "\n\033[1;35m********************************************\033[0m\n";
    std::cout << "\033[1;35m**        Welcome to Animal Sound Tests! **\033[0m\n";
    std::cout << "\033[1;35m********************************************\033[0m\n";

    // Crear un array de punteros a Animal (mitad Dog, mitad Cat)
    const int animalCount = 6;
    const Animal* animals[animalCount];
    std::cout << "\n\033[1;36m--- Creating Animals ---\033[0m\n";
    for (int i = 0; i < animalCount; ++i) {
        if (i < animalCount / 2) {
            animals[i] = new Dog(); // Crea un nuevo objeto Dog
        } else {
            animals[i] = new Cat(); // Crea un nuevo objeto Cat
        }
    }

    // Probar los sonidos
    std::cout << "\n\033[1;33m--- Testing makeSound() for Animals in the array ---\033[0m\n";
    for (int i = 0; i < animalCount; ++i) {
        animals[i]->makeSound(); // Llama al método makeSound de cada animal
    }

    // Probar deep copy
    std::cout << "\n\033[1;33m--- Testing Deep Copy ---\033[0m\n";
    Dog originalDog; // Crea un perro original
    originalDog.getBrain()->setIdea(0, "Fetch the ball!"); // Establece una idea en el cerebro
    Dog copiedDog = originalDog; // Crea una copia del perro original

    std::cout << "Original Dog's idea[0]: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog's idea[0]: " << copiedDog.getBrain()->getIdea(0) << std::endl;

    // Modificar la idea en el perro original
    originalDog.getBrain()->setIdea(0, "Chase the cat!");
    std::cout << "After modification, Original Dog's idea[0]: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog's idea[0] (should be unchanged): " << copiedDog.getBrain()->getIdea(0) << std::endl;

    // Eliminar todos los animales
    std::cout << "\n\033[1;36m--- Deleting Animals ---\033[0m\n";
    for (int i = 0; i < animalCount; ++i) {
        delete animals[i]; // Elimina cada objeto creado
    }

    std::cout << "\n\033[1;35m********************************************\033[0m\n";
    std::cout << "\033[1;35m**    All tests complete. Exiting...    **\033[0m\n";
    std::cout << "\033[1;35m********************************************\033[0m\n";

    return 0;
}