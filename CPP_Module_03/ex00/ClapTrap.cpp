/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:56:11 by manufern          #+#    #+#             */
/*   Updated: 2024/11/25 11:18:38 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string Name)
{
    std::cout << "A brave ClapTrap named \"" << Name << "\" has entered the battlefield!" << std::endl;
    this->Name = Name;
    this->HitPoint = 10;
    this->EnegyPoints = 10;
    this->AttackDamage = 0;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap \"" << this->Name << "\" bids farewell, leaving behind a legacy of courage." << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copy constructor: A new ClapTrap named \"" << other.Name 
              << "\" has been forged, inheriting its attributes!" << std::endl;
    this->Name = other.Name;
    this->HitPoint = other.HitPoint;
    this->EnegyPoints = other.EnegyPoints;
    this->AttackDamage = other.AttackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Copy assignment: ClapTrap \"" << this->Name 
              << "\" is taking on the identity and strengths of \"" 
              << other.Name << "\"." << std::endl;
    if (this != &other)
    {
        this->Name = other.Name;
        this->HitPoint = other.HitPoint;
        this->EnegyPoints = other.EnegyPoints;
        this->AttackDamage = other.AttackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (EnegyPoints > 0 && HitPoint > 0)
    {
        EnegyPoints--;
        std::cout << "ClapTrap <" << Name << "> attacks <" << target 
                  << ">, causing <" << AttackDamage << "> points of damage!" << std::endl;
    }
    else if (HitPoint <= 0)
    {
        std::cout << "ClapTrap <" << Name << "> cannot attack because it has no Hit Points left!" << std::endl;
    } else
    {
        std::cout << "ClapTrap <" << Name << "> cannot attack due to insufficient energy!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (HitPoint > 0)
    {
        unsigned int damageTaken;
        if (amount >= HitPoint)
        {
            damageTaken = HitPoint;
        } else
        {
            damageTaken = amount;
        }
        HitPoint -= damageTaken;
        std::cout << "ClapTrap <" << Name << "> takes <" << damageTaken 
                  << "> points of damage! Remaining Hit Points: <" << HitPoint << ">." << std::endl;

        if (HitPoint == 0)
        {
            std::cout << "ClapTrap <" << Name << "> has been destroyed!" << std::endl;
        }
    }
    else
    {
        std::cout << "ClapTrap <" << Name << "> is already destroyed and cannot take more damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (EnegyPoints > 0 && HitPoint > 0)
    {
        EnegyPoints--;
        HitPoint += amount;
        std::cout << "ClapTrap <" << Name << "> repairs itself for <" << amount 
                  << "> points! Current Hit Points: <" << HitPoint << ">." << std::endl;
    }
    else if (HitPoint <= 0)
    {
        std::cout << "ClapTrap <" << Name << "> cannot repair itself because it is destroyed!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap <" << Name << "> cannot repair itself due to insufficient energy!" << std::endl;
    }
}