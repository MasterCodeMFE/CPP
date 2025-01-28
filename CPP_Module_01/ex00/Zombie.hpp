/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassZombie.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:30:44 by manufern          #+#    #+#             */
/*   Updated: 2024/12/02 14:40:14 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <ctime>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void announce(void);
};

Zombie* newZombie( std::string name);
void randomChump( std::string name);

#endif