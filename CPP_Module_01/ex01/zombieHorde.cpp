/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:06:46 by manufern          #+#    #+#             */
/*   Updated: 2024/10/17 14:38:12 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *zombie_horder = new Zombie[N];
    int i = 0;
    if (N > 0)
    {
        while(i < N)
        {
           zombie_horder[i] = Zombie(name);
           i++;
        }
    }
    return (zombie_horder);
}