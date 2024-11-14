/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:50:28 by manufern          #+#    #+#             */
/*   Updated: 2024/10/21 12:11:08 by manufern         ###   ########.fr       */
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
        
        std::string getName() const {return (name);};
        
        void attack();
        void setWeapon(Weapon &weapon);
};
#endif