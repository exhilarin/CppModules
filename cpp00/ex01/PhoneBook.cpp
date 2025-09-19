/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:26:14 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/09/20 01:22:31 by ilyas-guney      ###   ########.fr       */
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
    printMessage(PHONEBOOK);

    Contact newContact;
    std::string input;

    std::cout << "\033[1;34mEnter first name: \033[0m";
    if (!std::getline(std::cin, input) || input.empty()) {
        reset();
        printMessage(SUCCESS, "\033[1;31m>>>         First name cannot be empty!        <<< \033[0m");
        return;
    }
    newContact.setFirstName(input);

    std::cout << "\033[1;35mEnter last name: \033[0m";
    if (!std::getline(std::cin, input) || input.empty()) {
        reset();
        printMessage(SUCCESS, "\033[1;31m>>>         Last name cannot be empty!         <<< \033[0m");
        return;
    }
    newContact.setLastName(input);

    std::cout << "\033[1;33mEnter nickname: \033[0m";
    if (!std::getline(std::cin, input) || input.empty()) {
        reset();
        printMessage(SUCCESS, "\033[1;31m>>>           Nickname cannot be empty!        <<< \033[0m");
        return;
    }
    newContact.setNickname(input);

    std::cout << "\033[1;32mEnter phone number: \033[0m";
    if (!std::getline(std::cin, input) || input.empty()) {
        reset();
        printMessage(SUCCESS, "\033[1;31m>>>        Phone number cannot be empty!       <<< \033[0m");
        return;
    }
    newContact.setPhoneNumber(input);

    std::cout << "\033[1;31mEnter darkest secret: \033[0m";
    if (!std::getline(std::cin, input) || input.empty()) {
        reset();
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
