#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "Contact.hpp"

enum MessageType { PHONEBOOK, PROMPT, WRONG_INPUT, EXIT, SUCCESS };

void printMessage(MessageType type, const std::string& extra = "");

class PhoneBook
{
	private:
	    Contact contacts[8];
	    int contactCount; 
	    int nextIndex;    

	public:
	    void add();
		void exit();
	    void search() const;

	private:
	    void displayTable() const;
	    void displayContact(int index) const;
};

#endif
