/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_contact.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:18:47 by manufern          #+#    #+#             */
/*   Updated: 2024/10/14 15:34:36 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLASS_CONTACT_HPP
#define CLASS_CONTACT_HPP
#include <string>
#include <iostream>
#include <cctype>
#include <iomanip>

class Contact
{
    private:
        std::string index;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secre;
    public:
        void set_index(std::string &id);
        void set_first_name(std::string &name);
        void set_last_name(std::string &last);
        void set_nickname(std::string &nick);
        void set_phone(std::string &phone);
        void set_darkest(std::string &darkest);

        std::string get_index() const { return index; }
        std::string get_first_name() const { return first_name; }
        std::string get_last_name() const { return last_name; }
        std::string get_nickname() const { return nickname; }
        std::string get_phone_number() const { return phone_number; }
        std::string get_darkest_secret() const { return darkest_secre; }
};

#endif