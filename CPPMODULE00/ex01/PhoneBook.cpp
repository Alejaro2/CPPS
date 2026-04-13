#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : _index(0), _count(0) {
}

PhoneBook::~PhoneBook() {
}

std::string PhoneBook::_getInput(std::string prompt, int mode) const {
    std::string input = "";
    bool valid = false;

    while (!valid) 
    {
        std::cout << prompt;
        
        if (!std::getline(std::cin, input))
            return "";

        if (input.empty()) 
        {
            std::cout << "Error: Field cannot be empty." << std::endl;
            continue;
        }

        bool formatError = false;
        size_t i = 0;

        if (mode == 1) {
            while (i < input.length()) {
                if (!std::isalpha(input[i]) && input[i] != ' ') {
                    std::cout << "Error: Only letters and spaces are allowed." << std::endl;
                    formatError = true;
                    break;
                }
                i++;
            }
        }
        else if (mode == 2) {
            while (i < input.length()) {
                if (!std::isdigit(input[i])) {
                    std::cout << "Error: Only digits are allowed." << std::endl;
                    formatError = true;
                    break;
                }
                i++;
            }
        }
        
        if (!formatError)
            valid = true;
    }
    return input;
}

std::string PhoneBook::_format(std::string text) const{
    if (text.length() > 10)
        return text.substr(0, 9) + ".";
    return text;
}


void PhoneBook::addContact() {
    int pos = this->_index % 8;

    if (this->_index > 7)
        std::cout << "Warning: Overwriting contact " << this->_contacts[pos].getFirstName() << std::endl;

    std::string first = _getInput("Enter a first name: ", 1);
    if (std::cin.eof()) return;

    std::string last = _getInput("Enter a last name: ", 1);
    if (std::cin.eof()) return;

    std::string nick = _getInput("Enter a nickname: ", 0);
    if (std::cin.eof()) return;

    std::string phone = _getInput("Enter a phone number: ", 2);
    if (std::cin.eof()) return;

    std::string secret = _getInput("Enter the darkest secret: ", 0);
    if (std::cin.eof()) return;

    this->_contacts[pos].setFirstName(first);
    this->_contacts[pos].setLastName(last);
    this->_contacts[pos].setNickname(nick);
    this->_contacts[pos].setPhoneNumber(phone);
    this->_contacts[pos].setDarkestSecret(secret);

    std::cout << "Contact saved [" << pos + 1 << "/8]" << std::endl;

    this->_index++;
    if (this->_count < 8)
        this->_count++;
}


void PhoneBook::searchContact(void) const {
    if (this->_count == 0) {
        std::cout << "Phonebook is empty. Use ADD first." << std::endl;
        return;
    }

    std::cout << "_____________________________________________" << std::endl;
    std::cout << "|" << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;
    std::cout << "|__________|__________|__________|__________|" << std::endl;

    int i = 0;
    while (i < this->_count) {
        std::cout << "|" << std::setw(10) << (i + 1) << "|"
                  << std::setw(10) << _format(this->_contacts[i].getFirstName()) << "|"
                  << std::setw(10) << _format(this->_contacts[i].getLastName()) << "|"
                  << std::setw(10) << _format(this->_contacts[i].getNickname()) << "|" << std::endl;
        i++;
    }
    std::cout << "_____________________________________________" << std::endl;

    std::string input;
    int index = -1;

    while (true) 
    {
        std::cout << "Enter index to view details: ";
        
        if (!std::getline(std::cin, input))
            return;

        if (input.length() == 1 && input[0] >= '0' && input[0] <= '9') {
            index = (input[0] - '0') - 1; 

            if (index >= 0 && index < this->_count) {
                std::cout << "\n--- Contact Details ---" << std::endl;
                std::cout << "First Name:     " << this->_contacts[index].getFirstName() << std::endl;
                std::cout << "Last Name:      " << this->_contacts[index].getLastName() << std::endl;
                std::cout << "Nickname:       " << this->_contacts[index].getNickname() << std::endl;
                std::cout << "Phone Number:   " << this->_contacts[index].getPhoneNumber() << std::endl;
                std::cout << "Darkest Secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
                break;
            } 
            else {
                std::cout << "Error: Index out of range. Try again." << std::endl;
            }
        } 
        else {
            std::cout << "Error: Invalid input (must be a single digit)." << std::endl;
        }
    }
}