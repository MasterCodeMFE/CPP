/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:55:44 by manufern          #+#    #+#             */
/*   Updated: 2024/10/18 09:50:01 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassZombie.hpp"

Zombie* newZombie( std::string name)
{
    Zombie *new_zombie;
    new_zombie = new Zombie(name);
    return (new_zombie);
}