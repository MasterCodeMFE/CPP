/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:50:28 by manufern          #+#    #+#             */
/*   Updated: 2024/12/02 15:52:17 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   HUMANB_HPP
# define  HUMANB_HPP
# include "Weapon.hpp"

class HumanB
{
    private:
        Weapon *weapon;
        std::string name;
    public:
        HumanB();
        HumanB(std::string name);
        ~HumanB();
        
        std::string getName() const;
        
        void attack();
        void setWeapon(Weapon &weapon);
};
#endif