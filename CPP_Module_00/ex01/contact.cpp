/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:45:56 by manufern          #+#    #+#             */
/*   Updated: 2024/10/14 14:54:09 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class_contact.hpp"
#include "class_phone_book.hpp"

void Contact::set_index(std::string &id)
{
    index = id;
    std::cout << "Index set to: " << index << std::endl; // Print del valor
}

void Contact::set_first_name(std::string &name)
{
    first_name = name;
    std::cout << "First Name set to: " << first_name << std::endl; // Print del valor
}

void Contact::set_last_name(std::string &last)
{
    last_name = last;
    std::cout << "Last Name set to: " << last_name << std::endl; // Print del valor
}

void Contact::set_nickname(std::string &nick)
{
    nickname = nick;
    std::cout << "Nickname set to: " << nickname << std::endl; // Print del valor
}

void Contact::set_phone(std::string &phone)
{
    phone_number = phone;
    std::cout << "phone_number set to: " << phone_number << std::endl;
}

void Contact::set_darkest(std::string &darkest)
{
    darkest_secre = darkest;
    std::cout << "darkest_secre set to: " << darkest_secre << std::endl;
}

void PhoneBook::add_contact(const Contact &new_contact, size_t index)
{
    contact[index] = new_contact;
}