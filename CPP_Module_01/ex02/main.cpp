/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:45:18 by manufern          #+#    #+#             */
/*   Updated: 2024/12/02 15:12:16 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>


void printColored(const std::string& text, const std::string& color)
{
    std::cout << color << text << "\033[0m"; // Reset color at the end
}

int main(void) {
    // Create a string and its pointer and reference
    std::string a = "HI THIS IS BRAIN";
    std::string *stringPTR = &a;
    std::string &stringREF = a;

    // Print memory addresses with decorations
    printColored("\n===========================================\n", "\033[1;34m");
    printColored("Memory Address Information:\n", "\033[1;32m");
    printColored("===========================================\n", "\033[1;34m");

    printColored("Memory address of string a:      ", "\033[1;36m");
    std::cout << &a << std::endl;

    printColored("Memory address of stringPTR:     ", "\033[1;36m");
    std::cout << stringPTR << std::endl;

    printColored("Memory address of stringREF:     ", "\033[1;36m");
    std::cout << &stringREF << std::endl;

    // Print values with decorations
    printColored("\n===========================================\n", "\033[1;34m");
    printColored("Value Information:\n", "\033[1;32m");
    printColored("===========================================\n", "\033[1;34m");

    printColored("Value of string a:               ", "\033[1;35m");
    std::cout << a << std::endl;

    printColored("Value pointed to by stringPTR:    ", "\033[1;35m");
    std::cout << stringPTR[0] << std::endl;

    printColored("Value referenced by stringREF:    ", "\033[1;35m");
    std::cout << stringREF << std::endl;

    printColored("\n===========================================\n", "\033[1;34m");
    printColored("End of Program\n", "\033[1;32m");
    printColored("===========================================\n", "\033[1;34m");

    return 0;
}