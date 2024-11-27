/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:22:33 by manufern          #+#    #+#             */
/*   Updated: 2024/11/27 16:44:31 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    // Introducción visual
    std::cout << "\n\033[1;35m********************************************\033[0m\n";  // Magenta para separar visualmente
    std::cout << "\033[1;35m**        Welcome to Animal Sound Tests! **\033[0m\n"; // Título en magenta
    std::cout << "\033[1;35m********************************************\033[0m\n";  // Magenta para separar visualmente

    // Creación de objetos
    std::cout << "\n\033[1;36m--- Creating Animal objects ---\033[0m\n"; // Título en cian
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    // Verificación de tipo y sonidos
    std::cout << "\n\033[1;33m--- Testing getType() and makeSound() ---\033[0m\n"; // Título en amarillo
    std::cout << "\033[1;32mType of Dog (j): \033[0m" << j->getType() << "\n"; // Verde para Dog
    std::cout << "\033[1;32mType of Cat (i): \033[0m" << i->getType() << "\n"; // Verde para Cat
    std::cout << "\033[1;32mType of Animal (meta): \033[0m" << meta->getType() << "\n"; // Verde para Animal

    std::cout << "\n\033[1;33m--- Testing makeSound() for each animal ---\033[0m\n"; // Título en amarillo
    i->makeSound(); // Expected: Meow!
    j->makeSound(); // Expected: Woof! Woof!
    meta->makeSound(); // Expected: Some generic animal sound!

    // Creación de WrongAnimal y WrongCat
    std::cout << "\n\033[1;36m--- Creating WrongAnimal and WrongCat objects ---\033[0m\n"; // Título en cian
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    // Verificación de tipo y sonidos de WrongAnimal y WrongCat
    std::cout << "\n\033[1;33m--- Testing getType() and makeSound() for wrong objects ---\033[0m\n"; // Título en amarillo
    std::cout << "\033[1;32mType of WrongCat (wrongCat): \033[0m" << wrongCat->getType() << "\n"; // Verde para WrongCat
    std::cout << "\033[1;32mType of WrongAnimal (wrongMeta): \033[0m" << wrongMeta->getType() << "\n"; // Verde para WrongAnimal

    std::cout << "\n\033[1;33m--- Testing makeSound() for wrong objects ---\033[0m\n"; // Título en amarillo
    wrongCat->makeSound(); // Expected: Some generic animal sound!
    wrongMeta->makeSound(); // Expected: Some generic animal sound!

    // Destrucción de objetos
    std::cout << "\n\033[1;36m--- Deleting animals ---\033[0m\n"; // Título en cian
    delete meta; // Expected: Animal destructor called
    delete j;    // Expected: Dog destructor called
    delete i;    // Expected: Cat destructor called
    delete wrongMeta; // Expected: WrongAnimal destructor called
    delete wrongCat; // Expected: WrongCat destructor called

    std::cout << "\n\033[1;35m********************************************\033[0m\n";  // Magenta para finalizar
    std::cout << "\033[1;35m**    All tests complete. Exiting...    **\033[0m\n"; // Mensaje final en magenta
    std::cout << "\033[1;35m********************************************\033[0m\n";  // Magenta para finalizar

    return 0;
}