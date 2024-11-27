/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:58:36 by manufern          #+#    #+#             */
/*   Updated: 2024/11/26 16:29:02 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
    std::cout << "ScavTrap constructor called for: " << Name << std::endl;
    this->HitPoint = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20; 
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for: " << ClapTrap::getName() << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called for: " << other.getName() << std::endl;
    this->HitPoint = other.getHitPoints();
    this->AttackDamage = other.getAttackDamage();
    this->EnergyPoints = other.getEnergyPoints();
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap assignment operator called for: " << other.getName() << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->HitPoint = other.HitPoint;
        this->AttackDamage = other.AttackDamage;
        this->EnergyPoints = other.EnergyPoints;
    }
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << ClapTrap::getName() << " is now in Gatekeeper mode!" << std::endl;
}