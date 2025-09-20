#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

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
