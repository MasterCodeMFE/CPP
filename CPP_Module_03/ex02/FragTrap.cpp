/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:21:21 by manufern          #+#    #+#             */
/*   Updated: 2024/11/26 12:43:11 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
    std::cout << "FragTrap constructor called for: " << Name << std::endl;
    this->HitPoint = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for: " << ClapTrap::getName() << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "Fragtrap copy constructor called for: " << other.getName() << std::endl;
    this->HitPoint = other.getHitPoints();
    this->AttackDamage = other.getAttackDamage();
    this->EnergyPoints = other.getEnergyPoints();
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "Fragtrap assignment operator called for: " << other.getName() << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->HitPoint = other.HitPoint;
        this->AttackDamage = other.AttackDamage;
        this->EnergyPoints = other.EnergyPoints;
    }
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << getName() << " says: High five! Let's make this epic! 🙌" << std::endl;
}