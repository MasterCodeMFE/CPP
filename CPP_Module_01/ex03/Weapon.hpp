/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:36:51 by manufern          #+#    #+#             */
/*   Updated: 2024/12/02 15:49:48 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  WEAPON_HPP
# define WEAPON_HPP
# include <string>
# include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		
		const std::string getType() const;
		
		void setType(std::string type);
};

#endif