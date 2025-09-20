/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:26:14 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/09/20 17:12:27 by ilyas-guney      ###   ########.fr       */
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
    std::cout << BYELLOW
              << "--------------------------------------------------\n"
              << "       ADDING NEW CONTACT TO THE PHONEBOOK...   \n"
              << "--------------------------------------------------"
              << RESET "\n";
    Contact newContact;
    std::string input;

    std::cout << BBLUE "Enter first name: " BYELLOW;
    if (!std::getline(std::cin, input) || input.empty()) {
        std::system("clear");
        printMessage(PHONEBOOK);
        printMessage(SUCCESS, BRED ">>>         First name cannot be empty!        <<< " RESET);
        return;
    }
    newContact.setFirstName(input);

    std::cout << BBLUE "Enter last name: " BYELLOW;
    if (!std::getline(std::cin, input) || input.empty()) {
        std::system("clear");
        printMessage(PHONEBOOK);
        printMessage(SUCCESS, BRED ">>>         Last name cannot be empty!         <<< " BYELLOW RESET);
        return;
    }
    newContact.setLastName(input);

    std::cout << BBLUE "Enter nickname: " BYELLOW;
    if (!std::getline(std::cin, input) || input.empty()) {
        std::system("clear");
        printMessage(PHONEBOOK);
        printMessage(SUCCESS, BRED ">>>           Nickname cannot be empty!        <<< " BYELLOW);
        return;
    }
    newContact.setNickname(input);

    std::cout << BBLUE "Enter phone number: " BYELLOW;
    if (!std::getline(std::cin, input) || input.empty()) {
        std::system("clear");
        printMessage(PHONEBOOK);
        printMessage(SUCCESS, BRED ">>>        Phone number cannot be empty!       <<< " BYELLOW);
        return;
    }
    newContact.setPhoneNumber(input);

    std::cout << BBLUE "Enter darkest secret: " BYELLOW;
    if (!std::getline(std::cin, input) || input.empty()) {
        std::system("clear");
        printMessage(PHONEBOOK);
        printMessage(SUCCESS, BRED ">>>       Darkest secret cannot be empty!      <<< " RESET);
        return;
    }
    newContact.setDarkestSecret(input);

    contacts[nextIndex] = newContact;
    nextIndex = (nextIndex + 1) % 8;
    if (contactCount < 8) contactCount++;

    std::system("clear");
    printMessage(PHONEBOOK);
    printMessage(SUCCESS, BGREEN ">>>         Contact added successfully!        <<<");
}

void PhoneBook::search()
{
    if (contactCount == 0)
    {
        system("clear");
        printMessage(PHONEBOOK);
        std::cout << BRED ">>>           No Contacts Saved Yet!           <<< " RESET "\n";
        return;
    }
    std::system("clear");
    displayTable();
    std::cout << BYELLOW <<"\n>>>     Enter index of the contact to view.    <<<\n" BBLUE;
    std::string line;
    std::getline(std::cin, line);
    if (line.empty())
    {
        system("clear");
        printMessage(PHONEBOOK);
        std::cout << BRED ">>>                Invalid index.              <<<" RESET << std::endl;
        return;
    }
    int idx = 0;
    for (size_t i = 0; i < line.size(); i++)
    {
        if (!isdigit(line[i]))
        {
            system("clear");
            printMessage(PHONEBOOK);
            std::cout << BRED ">>>                Invalid index.              <<<" RESET << std::endl;
            return;
        }
        idx = idx * 10 + (line[i] - '0');
    }
    if (idx < 0 || idx >= contactCount)
    {
        system("clear");
        printMessage(PHONEBOOK);
        std::cout << BRED ">>>                Invalid index.              <<<" RESET << std::endl;
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
    std::cout << BYELLOW
              << "--------------------------------------------------\n"
              << "                 CONTACT LIST                    \n"
              << "--------------------------------------------------"
              << RESET "\n";
    std::cout << BBLUE
              << std::setw(5) << "Index" << "|"
              << std::setw(12) << "First Name" << "|"
              << std::setw(12) << "Last Name" << "|"
              << std::setw(12) << "Nickname"
              << RESET << std::endl;
    std::cout <<  BBLUE << "--------------------------------------------------" RESET "\n";
    for (int i = 0; i < contactCount; i++)
    {
        std::cout << BYELLOW << std::setw(5) << i << RESET "|"
                  << BYELLOW << std::setw(12) 
                  << formatfield(contacts[i].getFirstName()) << RESET "|"
                  << BYELLOW << std::setw(12) 
                  << formatfield(contacts[i].getLastName()) << RESET "|"
                  << BYELLOW << std::setw(12) 
                  << formatfield(contacts[i].getNickname()) << RESET
                  << std::endl;
    }
    std::cout << BBLUE << "--------------------------------------------------" RESET;
}

void PhoneBook::displayContact(int index)
{
    if (index < 0 || index >= contactCount)
    {
        std::cout << BRED ">>> Invalid index. <<<" RESET << std::endl;
        return;
    }
    const Contact &c = contacts[index];
    std::cout << BYELLOW
              << "--------------------------------------------------\n"
              << "                 CONTACT DETAILS                 \n"
              << "--------------------------------------------------"
              << RESET "\n";
    std::cout << BBLUE "First Name:     " RESET BYELLOW << c.getFirstName() << RESET "\n";
    std::cout << BBLUE "Last Name:      " RESET BYELLOW << c.getLastName() << RESET "\n";
    std::cout << BBLUE "Nickname:       " RESET BYELLOW << c.getNickname() << RESET "\n";
    std::cout << BBLUE "Phone Number:   " RESET BYELLOW << c.getPhoneNumber() << RESET "\n";
    std::cout << BBLUE "Darkest Secret: " RESET BYELLOW << c.getDarkestSecret() << RESET "\n";
    std::cout << BYELLOW "--------------------------------------------------" RESET "\n";
}
