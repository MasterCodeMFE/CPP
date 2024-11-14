/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassZombie.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:30:44 by manufern          #+#    #+#             */
/*   Updated: 2024/10/18 09:49:52 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CLASSZOMBIE_HPP
# define CLASSZOMBIE_HPP
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