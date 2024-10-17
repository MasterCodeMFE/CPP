/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:00:25 by manufern          #+#    #+#             */
/*   Updated: 2024/10/17 17:09:04 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

HumanB::HumanB()
{
    std::cout << "Constructor Human B called." << std::endl;
}

HumanB::HumanB(std::string name)
{
    std::cout << "Constructor Human B called." << std::endl;
    this->name = name;
    this->weapon = NULL;
}

HumanB::~HumanB()
{
    std::cout << "Destructor Human B called." << std::endl;
}

void HumanB::attack(void)
{
    std::cout << getName() << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}