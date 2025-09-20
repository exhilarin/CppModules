/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:11:25 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/09/20 13:41:21 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	std::srand(std::time(0));
    system("clear");
    PhoneBook phonebook;
    std::string prompt;
    printMessage(PHONEBOOK);
    while (1)
    {
        printMessage(PROMPT);
        if (!std::getline(std::cin, prompt)) break;

        if (prompt == "EXIT")
            phonebook.exit();
        else if (prompt == "ADD")
            phonebook.add();
        else if (prompt == "SEARCH")
            phonebook.search();
        else
            printMessage(ERROR);
    }
    return 0;
}

void printMessage(MessageType type, const std::string& extra)
{
    switch(type)
    {
        case PHONEBOOK:
            std::cout << "\033[1;36m"
                      << "--------------------------------------------------\n"
                      << "           WELCOME TO VIRTUAL PHONEBOOK!    \n"
                      << "--------------------------------------------------"
                      << "\033[0m\n";
            break;

        case PROMPT:
            std::cout << "\033[1;33m>>> PLEASE ENTER A PROMPT: ADD | SEARCH | EXIT <<<\033[0m\n";
            break;

        case ERROR:
            system("clear");
            printMessage(PHONEBOOK);
            std::cout << "\033[1;31m>>>       WRONG INPUT! Please try again.       <<<\033[0m\n";
            break;

        case EXIT:
        {
            system("clear");
            std::string messages[] = {
                "\033[1;31mGoodbye! Your contacts are lost forever... 💀\033[0m",
                "\033[1;33mExiting PhoneBook... Poof! All contacts vanished into the void! ✨\033[0m",
                "\033[1;34mMission aborted. Your secrets are safe... or maybe not. 🤫\033[0m",
                "\033[1;35mEXIT detected. Contacts self-destructing in 3... 2... 1... 💥\033[0m"
            };
            int randomIndex = rand() % 4;
            std::cout << messages[randomIndex] << "\n\n";
            break;
        }

        case SUCCESS:
            std::cout << "\033[1;32m" << extra << "\033[0m\n";
            break;

        default:
            break;
    }
}
