/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassZombie.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:04:34 by manufern          #+#    #+#             */
/*   Updated: 2024/10/18 09:48:56 by manufern         ###   ########.fr       */
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

Zombie* zombieHorde(int N, std::string name);

#endif