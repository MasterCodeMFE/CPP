/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:15:24 by manufern          #+#    #+#             */
/*   Updated: 2024/11/27 12:17:44 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    private:

    public:
        WrongCat();
        ~WrongCat();
        WrongCat(const WrongCat& other);
        WrongCat& operator=(const WrongCat& other);
        void makeSound() const override; // Sobrescribe el método
};

#endif