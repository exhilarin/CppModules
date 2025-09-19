/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:26:14 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/09/20 00:35:39 by ilyas-guney      ###   ########.fr       */
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

    std::cout << "\033[1;35mEnter first name: \033[0m";
    if (!std::getline(std::cin, input) || input.empty()) return;
    newContact.setFirstName(input);

    std::cout << "\033[1;35mEnter last name: \033[0m";
    if (!std::getline(std::cin, input) || input.empty()) return;
    newContact.setLastName(input);

    std::cout << "\033[1;35mEnter nickname: \033[0m";
    if (!std::getline(std::cin, input) || input.empty()) return;
    newContact.setNickname(input);

    std::cout << "\033[1;35mEnter phone number: \033[0m";
    if (!std::getline(std::cin, input) || input.empty()) return;
    newContact.setPhoneNumber(input);

    std::cout << "\033[1;35mEnter darkest secret: \033[0m";
    if (!std::getline(std::cin, input) || input.empty()) return;
    newContact.setDarkestSecret(input);

    contacts[nextIndex] = newContact;
    nextIndex = (nextIndex + 1) % 8;
    if (contactCount < 8) contactCount++;

    std::system("clear");
    printMessage(PHONEBOOK);
    printMessage(SUCCESS, ">>>         Contact added successfully!        <<<");
}
