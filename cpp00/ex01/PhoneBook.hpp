#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define BBLACK      "\033[1;30m"
# define BRED        "\033[1;31m"
# define BGREEN      "\033[1;32m"
# define BYELLOW     "\033[1;33m"
# define BBLUE       "\033[1;34m"
# define BMAGENTA    "\033[1;35m"
# define BCYAN       "\033[1;36m"
# define BWHITE      "\033[1;37m"
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
