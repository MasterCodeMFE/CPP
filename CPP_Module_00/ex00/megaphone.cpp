/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:25:06 by manufern          #+#    #+#             */
/*   Updated: 2024/10/11 11:04:48 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    int i;
    int j;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        i = 1;
        while (i < argc)
        {
            j = 0;
            while (argv[i][j] != '\0')
            {
                std::cout << (char)toupper(argv[i][j]);
                j ++;
            }
            i ++;
        }
        std::cout << std::endl;
    }
    return (0);
}
