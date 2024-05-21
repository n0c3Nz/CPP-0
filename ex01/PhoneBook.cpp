/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:06:17 by guortun-          #+#    #+#             */
/*   Updated: 2024/05/20 17:06:18 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>  // Para std::strtol y exit

PhoneBook::PhoneBook() : index(0), count(0) {}

void PhoneBook::addContact() {
    if (count < 8) {
        count++;
    }
    if (index == 8) {
        index = 0;
    }
    contacts[index].inputContact();
    index++;
}

std::string PhoneBook::formatField(const std::string& field) const {
    if (field.length() > 10) {
        return field.substr(0, 9) + ".";
    } else {
        return field;
    }
}

bool PhoneBook::isNumber(const std::string& str) const {
    if (str.empty() || str.find_first_not_of(' ') == std::string::npos) {
        return false;
    }
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it))
            return false;
    }
    return true;
}

void PhoneBook::searchContacts() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < count; i++) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getLastName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getNickname()) << std::endl;
    }

    std::cout << "Enter index of contact to display: ";
    std::string input;
    if (!std::getline(std::cin, input)) {
        std::cout << "\nEOF received. Exiting program." << std::endl;
        exit(0);
    }
    if (!isNumber(input)) {
        std::cout << "Invalid index. Please enter a number." << std::endl;
        return;
    }

    long idx;
    try {
        idx = std::stol(input);
    } catch (const std::out_of_range& e) {
        std::cout << "Index out of range. Please enter a valid number." << std::endl;
        return;
    }

    if (idx >= 0 && idx < count) {
        contacts[idx].displayContact();
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}
