#include <iostream>
#include <fstream>
#include <stdio.h>

int	main(int ac, char **av)
{
	std::string 	temp;
	std::string 	hugeline;
	std::string		s1;
	std::string		s2;
	std::string		rep;
	std::ifstream	file;
	std::ofstream	output;
	unsigned long	num;
	
	if (ac == 4 && av[2][0] && av[3][0] && av[1][0])
	{
		s1.append(av[2]);
		s2.append(av[3]);
		rep.append(av[1]);
		rep.append(".replace");
		file.open(av[1]);
		do
		{
			std::getline(file, temp);
			hugeline.append(temp);
			hugeline.append("\n");
		} while (temp.length() > 0);
		hugeline.erase(hugeline.end() - 1);
		num = hugeline.find(s1);
		while (num < hugeline.length())
		{
			hugeline.erase(num, s1.length());
			hugeline.insert(num, s2);
			num = hugeline.find(s1, num + s2.length());
		}
		output.open(rep);
		output << hugeline;
		file.close();
		output.close();
		std::cout << "Done! \"" << s1 << "\" has been replaced to \"" << s2 << "\"\n";
	}
	else
	{
		std::cout << "Bad input\n";
		return (0);
	}
}
