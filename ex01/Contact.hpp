/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guortun- <guortun-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:06:10 by guortun-          #+#    #+#             */
/*   Updated: 2024/07/24 12:49:40 by guortun-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <climits>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    void inputContact();
    void displayContact() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;

    bool isNumber(const std::string& str) const;
    bool isValidNumber(const std::string& str) const;
    bool isValidInput(const std::string& str) const;
};

#endif
