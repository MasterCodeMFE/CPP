/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:44:32 by manufern          #+#    #+#             */
/*   Updated: 2024/11/26 17:44:56 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp" 

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
		  std::string name;
    
    public:
        DiamondTrap();
        DiamondTrap(const std::string Name);
        ~DiamondTrap();

        DiamondTrap(const DiamondTrap& other);
        DiamondTrap& operator=(const DiamondTrap& other);

        void whoAmI();
};

#endif