/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:19:28 by manufern          #+#    #+#             */
/*   Updated: 2024/11/26 17:45:12 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

    int main()
    {
        std::cout << "\n✨=== Welcome to the VaultHunter Training Arena! ===✨\n" << std::endl;

        std::cout << "In the world of Pandora, where chaos reigns and explosions are a way of life, "
                << "one legend rises to prove its mettle...\n" << std::endl;

        // Creación de un objeto DiamondTrap
        DiamondTrap diamondTrap("VaultHunter");
        std::cout << diamondTrap.getEnergyPoints() << std::endl;
        std::cout << diamondTrap.getAttackDamage() << std::endl;

    std::cout << "\n🤖 --- Testing DiamondTrap's Capabilities --- 🤖\n" << std::endl;

    // Demonstraremos su habilidad para atacar (heredada de ClapTrap)
    std::cout << "💥 --- VaultHunter attacks --- 💥" << std::endl;
    diamondTrap.attack("Handsome Jack");

    // Handsome Jack recibe daño
    std::cout << "\n💥 --- Handsome Jack Takes a Hit! --- 💥\n" << std::endl;
    std::cout << "Handsome Jack: 'That wasn't even a scratch!'\n";
    diamondTrap.takeDamage(10); // VaultHunter recibe daño

    std::cout << "\n⚡ --- Testing DiamondTrap's Self Repair --- ⚡\n" << std::endl;
    std::cout << "VaultHunter pulls out a wrench and starts repairing itself... 'Much better!'\n";
    diamondTrap.beRepaired(10);  // Repara a DiamondTrap

    // Test de ataque repetido
    std::cout << "\n🎯 --- Attacking Again --- 🎯\n";
    for (int i = 0; i < 5; i++)
    {
        diamondTrap.attack("Handsome Jack");
    }

    // Ensayo de los métodos exclusivos de DiamondTrap
    std::cout << "\n💥 --- DiamondTrap's Unique Features --- 💥\n" << std::endl;

    // `whoAmI` de DiamondTrap
    std::cout << "VaultHunter says: ";
    diamondTrap.whoAmI();

    // Uso del High Five de FragTrap
    std::cout << "\n✋ --- VaultHunter requests a high five! --- ✋\n" << std::endl;
    diamondTrap.highFivesGuys();

    // Uso de `guardGate` de ScavTrap
    std::cout << "\n🛡️ --- VaultHunter enters guard mode! --- 🛡️\n" << std::endl;
    diamondTrap.guardGate();

    // Handsome Jack recibe otro golpe
    std::cout << "\n💥 --- Handsome Jack Takes Another Hit! --- 💥\n" << std::endl;
    diamondTrap.takeDamage(25); // Handsome Jack recibe más daño

    // Probamos el comportamiento de cuando se acaba la energía
    std::cout << "\n⚡ --- DiamondTrap Runs Out of Energy --- ⚡\n" << std::endl;
    int energyCount = 3;
    while (energyCount > 0)
    {
        std::cout << "VaultHunter attacks again!\n";
        diamondTrap.attack("Handsome Jack");
        energyCount--;
    }

    std::cout << "\n🛠️ --- VaultHunter Needs More Energy --- 🛠️\n" << std::endl;
    std::cout << "VaultHunter: 'I need more energy! I’m out!'\n";

    // Usamos `guardGate` nuevamente
    diamondTrap.guardGate();  // VaultHunter guarda la puerta, aunque esté sin energía

    std::cout << "\n🎮 --- Combat Sequence Complete --- 🎮\n" << std::endl;
    std::cout << "The battle has been fierce, but VaultHunter stands victorious.\n";

    std::cout << "\n✨=== Simulation Complete ===✨\n" << std::endl;
    std::cout << "The VaultHunter Training Arena falls silent, "
              << "but the legend of VaultHunter will echo in Pandora... until the next battle.\n\n";

    return 0;
}
