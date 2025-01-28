/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:01:06 by manufern          #+#    #+#             */
/*   Updated: 2024/12/02 15:05:15 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    // Header
    std::cout << "\033[1;34m*******************************\033[0m" << std::endl;
    std::cout << "\033[1;34m      Zombie Announcement     \033[0m" << std::endl;
    std::cout << "\033[1;34m*******************************\033[0m" << std::endl;

    // Preparation message
    std::cout << "\n🔔 Preparing the zombies...\n";

    // Create zombies
    Zombie a;  // Zombie without a name
    Zombie b("Pepe");  // Zombie with a name
    Zombie* c;

    // Announce zombies
    std::cout << "\n🧟‍♂️ Announcing Zombies:\n";
    a.announce();
    std::cout << "👻 ";
    b.announce();

    c = newZombie("Luis");  // Dynamically create a new zombie
    c->announce();

    // Announce a temporary zombie
    std::cout << "\n🌟 Random Zombie Chump:\n";
    randomChump("Manuel");

    // Clean up memory
    delete(c);

    // Final message with a new style
    std::cout << "\n";
    std::cout << "\033[1;35m*******************************\033[0m" << std::endl;
    std::cout << "\033[1;35m       ZOMBIE ANNOUNCEMENT      \033[0m" << std::endl;
    std::cout << "\033[1;35m*******************************\033[0m" << std::endl;

    return 0;
}