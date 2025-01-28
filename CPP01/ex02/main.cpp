#include <iostream>

int main(void)
{
	std::string string("HI THIS IS BRAIN");
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "string " << &string << "\nptr " << stringPTR << "\nref " << &stringREF << "\n";
	std::cout << "string " << string << "\nptr " << *stringPTR << "\nref " << stringREF << "\n";
}
