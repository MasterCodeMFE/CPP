/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:00:13 by manufern          #+#    #+#             */
/*   Updated: 2024/12/02 15:51:17 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

HumanA::HumanA()
{
    std::cout << "Constructor Human A called." << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon)
{
    std::cout << "Constructor Human A called." << std::endl;
    this->name = name;
    this->weapon = &weapon;
}

HumanA::~HumanA()
{
    std::cout << "Destructor Human A called." << std::endl;
}

void HumanA::attack(void)
{
    std::cout << getName() << " attacks with their " << weapon->getType() << std::endl;
}

void HumanA::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

const std::string HumanA::getName() const
{
    return (name);
}