#include <iostream>
#include "PhoneBook.hpp"
int main() {
    PhoneBook phoneBook;
    std::string command;
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) {
            std::cout << "\nEOF received. Exiting program." << std::endl;
            exit(0);
        }
        if (command == "ADD") {
            phoneBook.addContact();
        } else if (command == "SEARCH") {
            phoneBook.searchContacts();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Unknown command. Please enter ADD, SEARCH, or EXIT." << std::endl;
        }
    }
    return 0;
}