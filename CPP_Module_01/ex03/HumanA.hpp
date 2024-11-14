/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:49:26 by manufern          #+#    #+#             */
/*   Updated: 2024/10/21 12:12:36 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"

class HumanA
{
    private:
        Weapon *weapon;
        std::string name;
    public:
        HumanA();
        HumanA(std::string name, Weapon & weapon);
        ~HumanA();

        std::string getName() const {return (name);};
        
        
        void attack(void);  
        void setWeapon(Weapon &weapon);
         
};
#endif