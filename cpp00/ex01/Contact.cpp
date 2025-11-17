
#include "PhoneBook.hpp"

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
