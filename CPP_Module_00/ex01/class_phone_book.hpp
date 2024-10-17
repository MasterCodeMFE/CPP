/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_phone_book.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manufern <manufern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:56:24 by manufern          #+#    #+#             */
/*   Updated: 2024/10/14 15:12:50 by manufern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_PHONE_BOOK_HPP
#define CLASS_PHONE_BOOK_HPP
#include "class_contact.hpp"


class PhoneBook
{
    private:
        Contact contact[8];
    public:
        void add_contact(const Contact &new_contact, size_t index);
        void initialize_contacts();
        void print_phone_book();
        void add_contact_to_phone_book(size_t &index);
};

#endif