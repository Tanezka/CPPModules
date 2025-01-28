#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

void    PhoneBook::view_contact(int i, PhoneBook *book)
{
	i--;
	if (i >= 0 && i < 8 && book->contacts[i].first_name.empty() == 0)
	{
		std::cout << "First name: " << book->contacts[i].first_name << "\n";
		std::cout << "Last name: " << book->contacts[i].last_name << "\n";
		std::cout << "Nickname: " << book->contacts[i].nickname << "\n";
		std::cout << "Phone number: " << book->contacts[i].phone_number << "\n";
		std::cout << "His/her little secret hehe: " << book->contacts[i].darkest_secret << "\n";
	}
	else
		std::cout << "Contact is empty or wrong index\n";
}

void	PhoneBook::print_string(std::string str)
{
	int len;

	len = str.length();
	if (len > 9)
		std::cout << "|" << std::setw(10) << str.substr(0, 9).append(".");
	else
		std::cout << "|" << std::setw(10) << str;
}

void	PhoneBook::search_contact(void)
{
	int	i;

	i = -1;
	std::cin.ignore();
	std::string line;
	std::cout << "+----------+----------+----------+----------+\n";
	std::cout << "|   index  |first name| last name| nickname |\n";
	while (++i < 8 && (contacts[i].first_name.empty() == 0))
	{
		std::cout << "|" << std::setw(10) << i + 1;
		PhoneBook::print_string(contacts[i].first_name);
		PhoneBook::print_string(contacts[i].last_name);
		PhoneBook::print_string(contacts[i].nickname);
		std::cout << "|\n";
	}
	std::cout << "+----------+----------+----------+----------+\n";
	std::cout << "select an index to view contact: ";
	std::getline(std::cin, line);
	PhoneBook::view_contact (atoi(line.c_str()), this);
}

void	PhoneBook::add_contact(void)
{
	int			i;
	static	int	k = 0;

    i = 0;
	std::cin.ignore();
    while (i < 8 && !(contacts[i].first_name.empty()))
        i++;	
    if (i == 8)
	{
        i = k;
	    if (++k > 7)
		    k = 0;
    }
    do
    {
	    std::cout << "Enter first name: ";
	    std::getline(std::cin, contacts[i].first_name);
    } while (contacts[i].first_name.empty() != 0 || isspace(static_cast<char>(contacts[i].first_name[0])) != 0);
    do
    {
	    std::cout << "Enter last name: ";
	    std::getline(std::cin, contacts[i].last_name);
    } while (contacts[i].last_name.empty() != 0 || isspace(static_cast<char>(contacts[i].last_name[0])) != 0);
    do
    {
	    std::cout << "Enter nickname: ";
	    std::getline(std::cin, contacts[i].nickname);
    } while (contacts[i].nickname.empty() != 0 || isspace(static_cast<char>(contacts[i].nickname[0])) != 0);
    do
    {
	    std::cout << "Enter phone number: ";
	    std::getline(std::cin, contacts[i].phone_number);
    } while (contacts[i].phone_number.empty() != 0 || isspace(static_cast<char>(contacts[i].phone_number[0])) != 0);
    do
    {
	    std::cout << "Enter darkest secret: ";
	    std::getline(std::cin, contacts[i].darkest_secret);
    } while (contacts[i].darkest_secret.empty() != 0 || isspace(static_cast<char>(contacts[i].darkest_secret[0])) != 0);
}
