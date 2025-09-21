/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:11:25 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/09/21 15:58:37 by ilyas-guney      ###   ########.fr       */
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
        if (!std::getline(std::cin, prompt))
            break;
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
            std::cout << YELLOW
                      << "--------------------------------------------------\n"
                      << "           WELCOME TO VIRTUAL PHONEBOOK!    \n"
                      << "--------------------------------------------------"
                      << RESET "\n";
            break;

        case PROMPT:
            std::cout << BLUE "+------------------------------------------------+\n";
            std::cout << BLUE "|      ADD      |     SEARCH     |      EXIT     |" RESET "\n";
            std::cout << BLUE "+------------------------------------------------+\n" YELLOW;
            break;

        case ERROR:
            system("clear");
            printMessage(PHONEBOOK);
            std::cout << RED ">>>       WRONG INPUT! Please try again.       <<<" RESET "\n";
            break;

        case EXIT:
        {
            system("clear");
            std::string messages[] = {
                RED "Goodbye! Your contacts are lost forever... 💀" RESET,
                YELLOW "Exiting PhoneBook... Poof! All contacts vanished into the void! ✨" RESET,
                BLUE "Mission aborted. Your secrets are safe... or maybe not. 🤫" RESET,
                MAGENTA "EXIT detected. Contacts self-destructing in 3... 2... 1... 💥" RESET
            };
            int randomIndex = rand() % 4;
            std::cout << messages[randomIndex] << "\n\n";
            break;
        }

        case SUCCESS:
            std::cout << GREEN << extra << RESET "\n";
            break;

        default:
            break;
    }
}
