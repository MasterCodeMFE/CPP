/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:29:18 by manufern          #+#    #+#             */
/*   Updated: 2025/07/02 15:00:46 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class_contact.hpp"
#include "class_phone_book.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

void PhoneBook::print_phone_book()
{
    size_t i = 0;

    std::cout << "|----------|----------|----------|----------|" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    while (i < 8)
    {
        std::string index_str = std::to_string(i + 1);
        std::string first_name = contact[i].get_first_name();
        std::string last_name = contact[i].get_last_name();
        std::string nickname = contact[i].get_nickname();
        if (first_name.empty() || last_name.empty() || nickname.empty())
        {
            i++;
            continue;
        }
        if (first_name.length() > 10)
        {
            first_name = first_name.substr(0, 9) + '.';
        }
        if (last_name.length() > 10)
        {
            last_name = last_name.substr(0, 9) + '.';
        }
        if (nickname.length() > 10)
        {
            nickname = nickname.substr(0, 9) + '.';
        }
        std::cout << "|"
                  << std::setw(10) << std::right << index_str << "|"
                  << std::setw(10) << std::right << first_name << "|"
                  << std::setw(10) << std::right << last_name << "|"
                  << std::setw(10) << std::right << nickname << "|"
                  << std::endl;
        i++;
    }
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    std::cout << "Enter the index of the contact you want to view (1-8): ";
    std::string input;
    std::getline(std::cin, input);
    int index;
    try {
	index = std::stoi(input);
    } catch (const std::invalid_argument& e) {
	    std::cout << "Eso no parece un número, illo. Prueba otra vez." << std::endl;
    } catch (const std::out_of_range& e) {
	    std::cout << "¡Eso es muy grande pa' un número! Relájate." << std::endl;
    }

    if (index < 0 || index >= 8)
    {
        std::cout << "Error: Index out of range!" << std::endl;
        return;
    }
    std::string first_name = contact[index].get_first_name();
    std::string last_name = contact[index].get_last_name();
    std::string nickname = contact[index].get_nickname();
    std::string phone_number = contact[index].get_phone_number();
    std::string darkest_secret = contact[index].get_darkest_secret();
    if (first_name.empty() || last_name.empty() || nickname.empty() ||
        phone_number.empty() || darkest_secret.empty())
    {
        std::cout << "Error: Contact has missing information!" << std::endl;
        return;
    }
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}


void PhoneBook::add_contact_to_phone_book(size_t &index)
{
    Contact new_contact;
    std::string temp;

    std::cout << "Enter first name: ";
    std::getline(std::cin, temp);
    if (temp.empty()) {
        std::cout << "First name cannot be empty." << std::endl;
        return;
    }void set_index(std::string &id);
        void set_first_name(std::string &name);
        void set_last_name(std::string &last);
        void set_nickname(std::string &nick);
        void set_phone(std::string &phone);
        void set_darkest(std::string &darkest);
    new_contact.set_first_name(temp);
    std::cout << "Enter last name: ";
    std::getline(std::cin, temp);
    if (temp.empty()) {
        std::cout << "Last name cannot be empty." << std::endl;
        return;
    }
    new_contact.set_last_name(temp);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, temp);
    if (temp.empty()) {
        std::cout << "Nickname cannot be empty." << std::endl;
        return;
    }
    new_contact.set_nickname(temp);
    
    std::cout << "Enter phone number: ";
    std::getline(std::cin, temp);
    if (temp.empty()) {
        std::cout << "Phone number cannot be empty." << std::endl;
        return;
    }
    new_contact.set_phone(temp);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, temp);
    if (temp.empty()) {
        std::cout << "Darkest secret cannot be empty." << std::endl;
        return;
    }
    new_contact.set_darkest(temp);
    add_contact(new_contact, index);
    index++;
    if (index == 8)
    {void set_index(std::string &id);
        void set_first_name(std::string &name);
        void set_last_name(std::string &last);
        void set_nickname(std::string &nick);
        void set_phone(std::string &phone);
        void set_darkest(std::string &darkest);
        index = 0;
    }
}

int main()
{
    size_t q;
    PhoneBook phone_book;
    q = 0;
    while (1)
    {
        std::string input;
        std::cout << std::endl
                  << "ADD: save a new contact" << std::endl
                  << "SEARCH: display a specific contact" << std::endl
                  << "EXIT: exit the program" << std::endl
                  << "What do you want to do? ";
        if (!std::getline(std::cin, input))
        {
            break;
        }
        size_t i = 0;
        while (i < input.length())
        {
            input[i] = std::toupper(input[i]);    
            i++;
        }
        if (input == "EXIT")
        {
            break;
        }
        else if (input == "SEARCH")
        {
            phone_book.print_phone_book();
        }
        else if (input == "ADD")
        {
            phone_book.add_contact_to_phone_book(q);
        }
    }
    return (0);
}