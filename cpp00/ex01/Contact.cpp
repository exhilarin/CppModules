/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:26:08 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/09/19 21:00:19 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Setters
void Contact::setFirstName(const std::string &str) {
    firstName = str;
}

void Contact::setLastName(const std::string &str) {
    lastName = str;
}

void Contact::setNickname(const std::string &str) {
    nickname = str;
}

void Contact::setPhoneNumber(const std::string &str) {
    phoneNumber = str;
}

void Contact::setDarkestSecret(const std::string &str) {
    darkestSecret = str;
}

// Getters
std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickname() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return darkestSecret;
}
