/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 21:11:25 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/09/20 16:59:25 by ilyas-guney      ###   ########.fr       */
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
            std::cout << BYELLOW
                      << "--------------------------------------------------\n"
                      << "           WELCOME TO VIRTUAL PHONEBOOK!    \n"
                      << "--------------------------------------------------"
                      << RESET "\n";
            break;

        case PROMPT:
            std::cout << BBLUE "+------------------------------------------------+\n";
            std::cout << BBLUE "|      ADD      |     SEARCH     |      EXIT     |" RESET "\n";
            std::cout << BBLUE "+------------------------------------------------+\n" BYELLOW;
            break;

        case ERROR:
            system("clear");
            printMessage(PHONEBOOK);
            std::cout << BRED ">>>       WRONG INPUT! Please try again.       <<<" RESET "\n";
            break;

        case EXIT:
        {
            system("clear");
            std::string messages[] = {
                BRED "Goodbye! Your contacts are lost forever... 💀" RESET,
                BYELLOW "Exiting PhoneBook... Poof! All contacts vanished into the void! ✨" RESET,
                BBLUE "Mission aborted. Your secrets are safe... or maybe not. 🤫" RESET,
                BMAGENTA "EXIT detected. Contacts self-destructing in 3... 2... 1... 💥" RESET
            };
            int randomIndex = rand() % 4;
            std::cout << messages[randomIndex] << "\n\n";
            break;
        }

        case SUCCESS:
            std::cout << BGREEN << extra << RESET "\n";
            break;

        default:
            break;
    }
}
