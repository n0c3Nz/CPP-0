/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:06:06 by guortun-          #+#    #+#             */
/*   Updated: 2024/07/24 14:06:17 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

long custom_stol(const std::string &str) {
    std::istringstream iss(str);
    long result;
    iss >> result;
    if (iss.fail() || !iss.eof()) {
        throw std::invalid_argument("Invalid argument for conversion to long");
    }
    return result;
}

bool Contact::isNumber(const std::string& str) const {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it))
            return false;
    }
    return true;
}

bool Contact::isValidNumber(const std::string& str) const {
    if (str.empty() || str.find_first_not_of(' ') == std::string::npos) {
        return false;
    }

    if (!isNumber(str)) return false;

    long num = std::strtol(str.c_str(), NULL, 10);
    if (num > INT_MAX || num < INT_MIN) {
        return false;
    }
    return true;
}

bool Contact::isValidInput(const std::string& str) const {
    return !str.empty() && str.find_first_not_of(' ') != std::string::npos;
}

void Contact::inputContact() {
    std::string input;

    while (true) {
        std::cout << "Enter first name: ";
        if (!std::getline(std::cin, input)) {
            std::cout << "\nEOF received. Exiting program." << std::endl;
            exit(0);
        }
        if (isValidInput(input)) {
            firstName = input;
            break;
        } else {
            std::cout << "Invalid input. Please enter a valid first name." << std::endl;
        }
    }

    while (true) {
        std::cout << "Enter last name: ";
        if (!std::getline(std::cin, input)) {
            std::cout << "\nEOF received. Exiting program." << std::endl;
            exit(0);
        }
        if (isValidInput(input)) {
            lastName = input;
            break;
        } else {
            std::cout << "Invalid input. Please enter a valid last name." << std::endl;
        }
    }

    while (true) {
        std::cout << "Enter nickname: ";
        if (!std::getline(std::cin, input)) {
            std::cout << "\nEOF received. Exiting program." << std::endl;
            exit(0);
        }
        if (isValidInput(input)) {
            nickname = input;
            break;
        } else {
            std::cout << "Invalid input. Please enter a valid nickname." << std::endl;
        }
    }

    while (true) {
        std::cout << "Enter phone number: ";
        if (!std::getline(std::cin, input)) {
            std::cout << "\nEOF received. Exiting program." << std::endl;
            exit(0);
        }
        if (isValidNumber(input)) {
            phoneNumber = input;
            break;
        } else {
            std::cout << "Invalid phone number. Please enter a valid number." << std::endl;
        }
    }

    while (true) {
        std::cout << "Enter darkest secret: ";
        if (!std::getline(std::cin, input)) {
            std::cout << "\nEOF received. Exiting program." << std::endl;
            exit(0);
        }
        if (isValidInput(input)) {
            darkestSecret = input;
            break;
        } else {
            std::cout << "Invalid input. Please enter a valid darkest secret." << std::endl;
        }
    }
}

void Contact::displayContact() const {
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl;
}

std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickname() const {
    return nickname;
}
