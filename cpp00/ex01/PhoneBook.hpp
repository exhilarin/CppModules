/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 00:43:45 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/09/29 00:43:46 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define RED        "\033[1;31m"
# define GREEN      "\033[1;32m"
# define YELLOW     "\033[1;33m"
# define BLUE       "\033[1;34m"
# define MAGENTA    "\033[1;35m"
# define RESET       "\033[0m"

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <limits>
# include <ctime>
# include "Contact.hpp"

enum MessageType { PHONEBOOK, PROMPT, ERROR, EXIT, SUCCESS };

void printMessage(MessageType type, const std::string& extra = "");

class PhoneBook
{
	private:
	    Contact contacts[8];
	    int contactCount; 
	    int nextIndex;    

	public:
		PhoneBook() : contactCount(0), nextIndex(0) {}
	    void add();
		void exit();
	    void search();

	private:
    	void displayTable();
    	void displayContact(int index);
};

#endif
