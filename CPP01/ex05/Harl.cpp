#include "Harl.hpp"
#include <iostream>


Harl::Harl()
{
	func_array[0] = &Harl::debug;
	func_array[1] = &Harl::info;
	func_array[2] = &Harl::warning;
	func_array[3] = &Harl::error;
}

Harl::~Harl()
{

}
void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void	Harl::error(void)
{
	std::cout <<"This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level)
{
	std::string array[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i;

	i = -1;
	while (++i < 5 && array[i].compare(level) != 0);
	if (i >= 0 && i < 5)
		(this->*func_array[i])();
	else
		std::cout << "Bad input\n";
}
