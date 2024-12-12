/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:56:11 by manufern          #+#    #+#             */
/*   Updated: 2024/11/26 16:46:11 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("Default"), HitPoint(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "ClapTrap default constructor called for: " << Name << std::endl;
}

ClapTrap::ClapTrap( std::string Name)
{
    std::cout << "A brave ClapTrap named \"" << Name << "\" has entered the battlefield!" << std::endl;
    this->Name = Name;
    this->HitPoint = 10;
    this->EnergyPoints = 10;
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
    this->EnergyPoints = other.EnergyPoints;
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
        this->EnergyPoints = other.EnergyPoints;
        this->AttackDamage = other.AttackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (EnergyPoints > 0 && HitPoint > 0)
    {
        EnergyPoints--;
        std::cout << "ClapTrap <" << this->Name << "> attacks <" << target 
                  << ">, causing <" << this->AttackDamage << "> points of damage!" << std::endl;
    }
    else if (HitPoint <= 0)
    {
        std::cout << "ClapTrap <" << this->Name << "> cannot attack because it has no Hit Points left!" << std::endl;
    } else
    {
        std::cout << "ClapTrap <" << this->Name << "> cannot attack due to insufficient energy!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->HitPoint > 0)
    {
        unsigned int damageTaken;
        if (amount >= (unsigned int) this->HitPoint)
        {
            damageTaken = this->HitPoint;
        } else
        {
            damageTaken = amount;
        }
        HitPoint -= damageTaken;
        std::cout << "ClapTrap <" << this->Name << "> takes <" << damageTaken 
                  << "> points of damage! Remaining Hit Points: <" << this->HitPoint << ">." << std::endl;

        if (HitPoint == 0)
        {
            std::cout << "ClapTrap <" << this->Name << "> has been destroyed!" << std::endl;
        }
    }
    else
    {
        std::cout << "ClapTrap <" << this->Name << "> is already destroyed and cannot take more damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (EnergyPoints > 0 && this->HitPoint > 0)
    {
        this->EnergyPoints--;
        HitPoint += amount;
        std::cout << "ClapTrap <" << this->Name << "> repairs itself for <" << amount 
                  << "> points! Current Hit Points: <" << this->HitPoint << ">." << std::endl;
    }
    else if (this->HitPoint <= 0)
    {
        std::cout << "ClapTrap <" << this->Name << "> cannot repair itself because it is destroyed!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap <" << this->Name << "> cannot repair itself due to insufficient energy!" << std::endl;
    }
}

std::string ClapTrap::getName() const
{
    return this->Name;
}

int ClapTrap::getHitPoints() const
{
    return this->HitPoint;
}

int ClapTrap::getEnergyPoints() const
{
    return this->EnergyPoints;
}

int ClapTrap::getAttackDamage() const
{
    return this->AttackDamage;
}