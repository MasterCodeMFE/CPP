/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:12:37 by manufern          #+#    #+#             */
/*   Updated: 2024/10/18 09:49:01 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassZombie.hpp"

int main(void)
{
    int n = 4;
    Zombie *a = zombieHorde(n, "Pepe");
    int i=0;
    while (i < n)
    {
        a[i].announce();
        i ++;
    }
    delete[](a);
    return 0;
}