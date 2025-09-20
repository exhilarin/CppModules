/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:26:14 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/09/20 13:20:22 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::exit(void)
{
    printMessage(EXIT);
    std::exit(0);
}

void PhoneBook::add()
{
    std::system("clear");
    std::cout << "\033[1;33m"
              << "--------------------------------------------------\n"
              << "         ADDING NEW CONTACT TO THE PHONEBOOK...  \n"
              << "--------------------------------------------------"
              << "\033[0m\n";
    Contact newContact;
    std::string input;

    std::cout << "\033[1;34mEnter first name: \033[0m";
    if (!std::getline(std::cin, input) || input.empty()) {
        std::system("clear");
        printMessage(PHONEBOOK);
        printMessage(SUCCESS, "\033[1;31m>>>         First name cannot be empty!        <<< \033[0m");
        return;
    }
    newContact.setFirstName(input);

    std::cout << "\033[1;35mEnter last name: \033[0m";
    if (!std::getline(std::cin, input) || input.empty()) {
        std::system("clear");
        printMessage(PHONEBOOK);
        printMessage(SUCCESS, "\033[1;31m>>>         Last name cannot be empty!         <<< \033[0m");
        return;
    }
    newContact.setLastName(input);

    std::cout << "\033[1;33mEnter nickname: \033[0m";
    if (!std::getline(std::cin, input) || input.empty()) {
        std::system("clear");
        printMessage(PHONEBOOK);
        printMessage(SUCCESS, "\033[1;31m>>>           Nickname cannot be empty!        <<< \033[0m");
        return;
    }
    newContact.setNickname(input);

    std::cout << "\033[1;32mEnter phone number: \033[0m";
    if (!std::getline(std::cin, input) || input.empty()) {
        std::system("clear");
        printMessage(PHONEBOOK);
        printMessage(SUCCESS, "\033[1;31m>>>        Phone number cannot be empty!       <<< \033[0m");
        return;
    }
    newContact.setPhoneNumber(input);

    std::cout << "\033[1;31mEnter darkest secret: \033[0m";
    if (!std::getline(std::cin, input) || input.empty()) {
        std::system("clear");
        printMessage(PHONEBOOK);
        printMessage(SUCCESS, "\033[1;31m>>>       Darkest secret cannot be empty!      <<< \033[0m");
        return;
    }
    newContact.setDarkestSecret(input);

    contacts[nextIndex] = newContact;
    nextIndex = (nextIndex + 1) % 8;
    if (contactCount < 8) contactCount++;

    std::system("clear");
    printMessage(PHONEBOOK);
    printMessage(SUCCESS, ">>>         Contact added successfully!        <<<");
}

void PhoneBook::search()
{
    if (contactCount == 0)
    {
        std::cout << "\033[1;31m>>>           No Contacts Saved Yet!           <<< \033[0m\n";
        return;
    }
    std::system("clear");
    displayTable();
    std::cout << "\nEnter index of the contact to view: ";
    int idx;
    if (!(std::cin >> idx) || idx < 0 || idx >= contactCount)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits < std::streamsize >::max(), '\n');
        std::cout << "Invalid Index";
        return;
    }
    displayContact(idx);
}

static std::string formatfield(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::displayTable()
{
    std::cout << "\033[1;33m"
              << "--------------------------------------------------\n"
              << "                 CONTACT LIST                    \n"
              << "--------------------------------------------------\n"
              << "\033[0m";
    std::cout << "\033[1;35m"
              << std::setw(5) << "Index" << "|"
              << std::setw(12) << "First Name" << "|"
              << std::setw(12) << "Last Name" << "|"
              << std::setw(12) << "Nickname"
              << "\033[0m" << std::endl;
    std::cout << "\033[1;37m--------------------------------------------------\033[0m\n";
    for (int i = 0; i < contactCount; i++)
    {
        std::cout << "\033[1;36m" << std::setw(5) << i << "\033[0m" << "|"
                  << "\033[1;32m" << std::setw(12) 
                  << formatfield(contacts[i].getFirstName()) << "\033[0m" << "|"
                  << "\033[1;32m" << std::setw(12) 
                  << formatfield(contacts[i].getLastName()) << "\033[0m" << "|"
                  << "\033[1;32m" << std::setw(12) 
                  << formatfield(contacts[i].getNickname()) << "\033[0m"
                  << std::endl;
    }
    std::cout << "\033[1;37m--------------------------------------------------\033[0m\n";
}


void PhoneBook::displayContact(int index)
{
    if (index < 0 || index >= contactCount)
    {
        std::cout << "\033[1;31m>>> Invalid index. <<<\033[0m" << std::endl;
        return;
    }
    const Contact &c = contacts[index];
    std::cout << "\033[1;33m"
              << "--------------------------------------------------\n"
              << "                 CONTACT DETAILS                 \n"
              << "--------------------------------------------------\n"
              << "\033[0m";
    std::cout << "\033[1;35mFirst Name:     \033[0m\033[1;32m" 
              << c.getFirstName() << "\033[0m\n";
    std::cout << "\033[1;35mLast Name:      \033[0m\033[1;32m" 
              << c.getLastName() << "\033[0m\n";
    std::cout << "\033[1;35mNickname:       \033[0m\033[1;32m" 
              << c.getNickname() << "\033[0m\n";
    std::cout << "\033[1;35mPhone Number:   \033[0m\033[1;32m" 
              << c.getPhoneNumber() << "\033[0m\n";
    std::cout << "\033[1;35mDarkest Secret: \033[0m\033[1;32m" 
              << c.getDarkestSecret() << "\033[0m\n";
    std::cout << "\033[1;37m--------------------------------------------------\n\033[0m";
}
