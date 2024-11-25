/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:01:06 by manufern          #+#    #+#             */
/*   Updated: 2024/10/18 09:49:56 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassZombie.hpp"

int main(void)
{
    Zombie a;
    Zombie b("pepe");
    Zombie *c;
    a.announce();
    b.announce();
    c = newZombie("Luis");
    c->announce();
    randomChump("Manuel");
    delete(c);
    return 0;
}