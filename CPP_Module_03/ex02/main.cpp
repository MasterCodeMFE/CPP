/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:19:28 by manufern          #+#    #+#             */
/*   Updated: 2024/11/26 12:42:07 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp" // Asegúrate de incluir esta cabecera

int main()
{
    std::cout << "\n✨=== Welcome to the VaultHunter Training Arena! ===✨\n" << std::endl;

    std::cout << "In the chaotic world of Pandora, "
              << "where explosions are a way of life and sarcasm flows like Eridium, "
              << "two legends prepare to test their mettle...\n" << std::endl;

    // Creating ClapTrap objects
    ClapTrap claptrap("CL4P-TP");  // Claptrap
    ClapTrap handsomeJack("Handsome Jack");

    std::cout << "\n🤖 --- Booting Combat Simulations --- 🤖\n" << std::endl;

    std::cout << "🎯 CL4P-TP primes its weapons with all the enthusiasm of a Hyperion intern...\n";
    claptrap.attack("Handsome Jack");

    std::cout << "\n💥 --- Handsome Jack Takes a Hit! --- 💥\n" << std::endl;
    std::cout << "Handsome Jack: 'Was that an attack, or were you just waving hello with bullets?'\n";
    handsomeJack.takeDamage(5);

    std::cout << "\n🔧 --- Self-Repair Activated --- 🔧\n" << std::endl;
    std::cout << "CL4P-TP pulls out a wrench and starts banging on itself. 'This is fine!' it insists.\n";
    claptrap.beRepaired(3);

    std::cout << "\n⚡ --- Testing Energy Resilience --- ⚡\n" << std::endl;
    std::cout << "CL4P-TP decides to fire wildly, claiming, 'Accuracy is overrated!'\n";
    int energyCount = 10;
    while (energyCount > 0)
    {
        claptrap.attack("Handsome Jack");
        energyCount--;
    }

    std::cout << "\n💀 --- Handsome Jack Hits the Ground! --- 💀\n" << std::endl;
    std::cout << "Handsome Jack: 'This isn't over! I'll just... lie down here for a second.'\n";
    handsomeJack.takeDamage(20);

    std::cout << "\n⚙️ --- Attempting a Comeback --- ⚙️\n" << std::endl;
    std::cout << "Handsome Jack: 'Hyperion bots, FIX ME!' But nothing happens...\n";
    handsomeJack.beRepaired(5);

    // Introducing ScavTrap
    std::cout << "\n🛡️ --- The ScavTrap Legacy Begins --- 🛡️\n" << std::endl;
    std::cout << "Enter ScavTrap, ready to guard the gates...\n";
    
    ScavTrap scavtrap("Scavenger");
    
    // ScavTrap uses its guardGate functionality
    scavtrap.guardGate(); // Displaying the Gatekeeper mode message

    std::cout << "\n🛠️ --- ScavTrap Combat Mode --- 🛠️\n" << std::endl;
    std::cout << "ScavTrap enters combat mode and prepares to defend Pandora...\n";
    scavtrap.attack("Handsome Jack");

    std::cout << "\n💥 --- Handsome Jack Takes Another Hit! --- 💥\n" << std::endl;
    handsomeJack.takeDamage(10);

    // Introducing FragTrap
    std::cout << "\n⚔️ --- FragTrap Joins the Battle --- ⚔️\n" << std::endl;
    std::cout << "Introducing FragTrap, the battle-hardened warrior...\n";

    FragTrap fragtrap("Fraggy");
    fragtrap.highFivesGuys(); // FragTrap requests a high five

    std::cout << "\n💥 --- FragTrap Combat Mode --- 💥\n" << std::endl;
    fragtrap.attack("Handsome Jack");

    std::cout << "\n🔥 --- Handsome Jack Takes Another Hit! --- 🔥\n" << std::endl;
    handsomeJack.takeDamage(15);

    std::cout << "\n✨=== Simulation Complete ===✨\n" << std::endl;
    std::cout << "The VaultHunter arena falls silent, "
              << "but the memory of this battle will echo in the halls of Hyperion...\n"
              << "Or at least until someone cleans up the mess.\n\n";

    std::cout << "Stay classy, Pandora! 🚀💥🤖\n" << std::endl;

    return 0;
}
