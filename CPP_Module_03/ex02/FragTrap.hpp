/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:21:24 by manufern          #+#    #+#             */
/*   Updated: 2024/11/26 12:37:00 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    private:

    public:
        FragTrap(std::string Name);
        ~FragTrap();
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        
        void highFivesGuys(void);
};


#endif