/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:24:40 by manufern          #+#    #+#             */
/*   Updated: 2024/12/02 16:06:11 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void) {
    Harl harl;

    // Header
    std::cout << "\033[1;34m===============================\033[0m" << std::endl;
    std::cout << "\033[1;34m        Harl Complains         \033[0m" << std::endl;
    std::cout << "\033[1;34m===============================\033[0m" << std::endl;

    // Complaints
    std::cout << "\033[1;36m> Harl is about to complain...\033[0m" << std::endl;
    
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    harl.complain("PEPE"); // Test with an unknown level

    // Footer
    std::cout << "\033[1;34m===============================\033[0m" << std::endl;
    std::cout << "\033[1;32mAll complaints have been processed!\033[0m" << std::endl;
    std::cout << "\033[1;34m===============================\033[0m" << std::endl;

    return 0;
}