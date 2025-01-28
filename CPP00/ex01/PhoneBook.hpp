#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
public:
	void	add_contact(void);
	void	search_contact(void);
	void	view_contact(int i, PhoneBook *book);
	void	print_string(std::string str);
};
#endif
