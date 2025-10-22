/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:26:14 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/09/23 16:23:43 by ilyas-guney      ###   ########.fr       */
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
    std::cout << YELLOW
              << "--------------------------------------------------\n"
              << "       ADDING NEW CONTACT TO THE PHONEBOOK...   \n"
              << "--------------------------------------------------"
              << RESET "\n";
    Contact newContact;
    std::string input;

    std::cout << BLUE "Enter first name: " YELLOW;
    if (!std::getline(std::cin, input) || input.empty()) {
        std::system("clear");
        printMessage(PHONEBOOK);
        printMessage(SUCCESS, RED ">>>         First name cannot be empty!        <<< " RESET);
        return;
    }
    newContact.setFirstName(input);

    std::cout << BLUE "Enter last name: " YELLOW;
    if (!std::getline(std::cin, input) || input.empty()) {
        std::system("clear");
        printMessage(PHONEBOOK);
        printMessage(SUCCESS, RED ">>>         Last name cannot be empty!         <<< " YELLOW RESET);
        return;
    }
    newContact.setLastName(input);

    std::cout << BLUE "Enter nickname: " YELLOW;
    if (!std::getline(std::cin, input) || input.empty()) {
        std::system("clear");
        printMessage(PHONEBOOK);
        printMessage(SUCCESS, RED ">>>           Nickname cannot be empty!        <<< " YELLOW);
        return;
    }
    newContact.setNickname(input);

    std::cout << BLUE "Enter phone number: " YELLOW;
    if (!std::getline(std::cin, input) || input.empty()) {
        std::system("clear");
        printMessage(PHONEBOOK);
        printMessage(SUCCESS, RED ">>>        Phone number cannot be empty!       <<< " YELLOW);
        return;
    }
    newContact.setPhoneNumber(input);

    std::cout << BLUE "Enter darkest secret: " YELLOW;
    if (!std::getline(std::cin, input) || input.empty()) {
        std::system("clear");
        printMessage(PHONEBOOK);
        printMessage(SUCCESS, RED ">>>       Darkest secret cannot be empty!      <<< " RESET);
        return;
    }
    newContact.setDarkestSecret(input);

    contacts[nextIndex] = newContact;
    nextIndex = (nextIndex + 1) % 8;
    if (contactCount < 8)
        contactCount++;
    std::system("clear");
    printMessage(PHONEBOOK);
    printMessage(SUCCESS, GREEN ">>>         Contact added successfully!        <<<");
}

void PhoneBook::search()
{
    if (contactCount == 0)
    {
        system("clear");
        printMessage(PHONEBOOK);
        std::cout << RED ">>>           No Contacts Saved Yet!           <<< " RESET "\n";
        return;
    }
    std::system("clear");
    displayTable();
    std::cout << YELLOW <<"\n>>>     Enter index of the contact to view.    <<<\n" BLUE;
    std::string line;
    std::getline(std::cin, line);
    if (line.empty())
    {
        system("clear");
        printMessage(PHONEBOOK);
        std::cout << RED ">>>                Invalid index.              <<<" RESET << std::endl;
        return;
    }
    int idx = 0;
    for (size_t i = 0; i < line.size(); i++)
    {
        if (!isdigit(line[i]))
        {
            system("clear");
            printMessage(PHONEBOOK);
            std::cout << RED ">>>                Invalid index.              <<<" RESET << std::endl;
            return;
        }
        idx = idx * 10 + (line[i] - '0');
    }
    if (idx < 0 || idx >= contactCount)
    {
        system("clear");
        printMessage(PHONEBOOK);
        std::cout << RED ">>>                Invalid index.              <<<" RESET << std::endl;
        return;
    }
    system("clear");
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
    std::cout << YELLOW
              << "--------------------------------------------------\n"
              << "                 CONTACT LIST                    \n"
              << "--------------------------------------------------"
              << RESET "\n";
    std::cout << BLUE
              << std::setw(5) << "Index" << "|"
              << std::setw(12) << "First Name" << "|"
              << std::setw(12) << "Last Name" << "|"
              << std::setw(12) << "Nickname"
              << RESET << std::endl;
    std::cout <<  BLUE << "--------------------------------------------------" RESET "\n";
    for (int i = 0; i < contactCount; i++)
    {
        std::cout << YELLOW << std::setw(5) << i << RESET "|"
                  << YELLOW << std::setw(12) 
                  << formatfield(contacts[i].getFirstName()) << RESET "|"
                  << YELLOW << std::setw(12) 
                  << formatfield(contacts[i].getLastName()) << RESET "|"
                  << YELLOW << std::setw(12) 
                  << formatfield(contacts[i].getNickname()) << RESET
                  << std::endl;
    }
    std::cout << BLUE << "--------------------------------------------------" RESET;
}

void PhoneBook::displayContact(int index)
{
    if (index < 0 || index >= contactCount)
    {
        std::cout << RED ">>> Invalid index. <<<" RESET << std::endl;
        return;
    }
    const Contact &c = contacts[index];
    std::cout << YELLOW
              << "--------------------------------------------------\n"
              << "                 CONTACT DETAILS                 \n"
              << "--------------------------------------------------"
              << RESET "\n";
    std::cout << BLUE "First Name:     " RESET YELLOW << c.getFirstName() << RESET "\n";
    std::cout << BLUE "Last Name:      " RESET YELLOW << c.getLastName() << RESET "\n";
    std::cout << BLUE "Nickname:       " RESET YELLOW << c.getNickname() << RESET "\n";
    std::cout << BLUE "Phone Number:   " RESET YELLOW << c.getPhoneNumber() << RESET "\n";
    std::cout << BLUE "Darkest Secret: " RESET YELLOW << c.getDarkestSecret() << RESET "\n";
    std::cout << YELLOW "--------------------------------------------------" RESET "\n";
}
