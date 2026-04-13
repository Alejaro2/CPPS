#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    PhoneBook book;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        
        if (!std::getline(std::cin, command))
            break;

        if (command == "EXIT")
            break;
        else if (command == "ADD")
            book.addContact();
        else if (command == "SEARCH")
            book.searchContact();
        if(std::cin.eof())
            break;
    }
    return 0;
}