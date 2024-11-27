    /* ************************************************************************** */
    /*                                                                            */
    /*                                                        :::      ::::::::   */
    /*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
    /*                                                    +:+ +:+         +:+     */
    /*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
    /*                                                +#+#+#+#+#+   +#+           */
    /*   Created: 2024/11/26 15:44:49 by manufern          #+#    #+#             */
    /*   Updated: 2024/11/26 17:57:01 by manufern         ###   ########.fr       */
    /*                                                                            */
    /* ************************************************************************** */

    #include "ClapTrap.hpp"
    #include "ScavTrap.hpp"
    #include "FragTrap.hpp" 
    #include "DiamondTrap.hpp"
    
DiamondTrap::DiamondTrap(const std::string Name) : FragTrap(Name), ScavTrap(Name)
{
    std::cout << "DiamondTrap constructor called for: " << Name << std::endl;
    this->name = Name;  // Asignamos el nombre específico para DiamondTrap
    ClapTrap::Name = Name + "_clap_name";  // Aseguramos que ClapTrap tenga el nombre con el sufijo "_clap_name"
    this->HitPoint = FragTrap::HitPoint;  // Usamos los HitPoints de FragTrap
    this->AttackDamage = FragTrap::AttackDamage;  // Usamos el AttackDamage de FragTrap
    this->EnergyPoints = ScavTrap::EnergyPoints;  // Usamos los EnergyPoints de ScavTrap
}

// Destructor
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called for: " << name << std::endl;
}

// Constructor de copia
DiamondTrap::DiamondTrap(const DiamondTrap& other) 
    : ScavTrap(other), FragTrap(other), name(other.name) 
{
    std::cout << "DiamondTrap copy constructor called for " << name << std::endl;
}

// Operador de asignación
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) 
{
    if (this != &other)
    {
        this->name = other.name;
        this->HitPoint = other.HitPoint;
        this->EnergyPoints = other.EnergyPoints;
        this->AttackDamage = other.AttackDamage;
        std::cout << "DiamondTrap assignment operator called for " << name << std::endl;
    }
    return *this;
}

// Función whoAmI
void DiamondTrap::whoAmI() 
{
    std::cout << "I am " << name << ", the DiamondTrap, "
              << "and I inherit from " << ClapTrap::Name 
              << " (ClapTrap)." << std::endl;
}