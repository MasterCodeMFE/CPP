/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:24:40 by manufern          #+#    #+#             */
/*   Updated: 2024/10/21 11:59:52 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		return (1);
	}
	int i = 0;
	std::string level = argv[1];
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    while (levels[i] != level && i < 5)
    {
        i ++;
    }
    switch (i)
    {
        case 0:
			std::cout << "[ DEBUG ]" << std::endl;
            harl.complain("DEBUG");
			harl.complain("INFO");
			harl.complain("WARNING");
			harl.complain("ERROR");
            break;
        case 1:
			std::cout << "[ INFO ]" << std::endl;
            harl.complain("INFO");
			harl.complain("WARNING");
			harl.complain("ERROR");
            break;
        case 2:
			std::cout << "[ WARNING ]" << std::endl;
            harl.complain("WARNING");
			harl.complain("ERROR");
            break;
        case 3:
			std::cout << "[ ERROR ]" << std::endl;
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
	return (0);
}