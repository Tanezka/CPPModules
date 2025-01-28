#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
    std::string command;
    PhoneBook book;
    while (1)
    {
		std::cout << "ADD - SEARCH - EXIT\nCommand> ";
        std::cin >> command;
        if (command.compare("ADD") == 0)
            book.add_contact();
		else if (command.compare("SEARCH") == 0)
			book.search_contact();
		else if (command.compare("EXIT") == 0)
			break;
    }
}
