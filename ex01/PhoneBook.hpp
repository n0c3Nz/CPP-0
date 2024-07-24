/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:06:24 by guortun-          #+#    #+#             */
/*   Updated: 2024/07/24 13:18:43 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>

class PhoneBook {
private:
    Contact contacts[8];
    int index;
    int count;

    std::string formatField(const std::string& field) const;
    bool isNumber(const std::string& str) const;

public:
    PhoneBook();
    void addContact();
    void searchContacts() const;
};

#endif
