#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using std::cout;
using std::endl;
using std::map;
using std::string;

Bitcoin::Bitcoin(): data_name("data.csv")
{

}

Bitcoin::Bitcoin(string av): data_name("data.csv"), input_name(av)
{

}

Bitcoin::~Bitcoin()
{

}
    
Bitcoin::Bitcoin(Bitcoin &source)
{
    *this = source;
}

Bitcoin &Bitcoin::operator=(const Bitcoin& source)
{
	std::map<std::string, float> copy_data(source.get_map());
	data_map = copy_data;
    return *this;
}

const	map<string, float>	&Bitcoin::get_map() const
{
	return data_map;
}

string  Bitcoin::findnearest(string date)
{
    string                             to_look;
    map<string, float>::iterator       it;
    map<string, float>::iterator       ite;

    it = data_map.begin();
    ite = it;
    ite++;
    while (ite != data_map.end())
    {
        if (it->first < date && ite->first > date)
            return (it->first);
        it++;
        ite++;
    }
    return date.substr(0,4);
}

bool    Bitcoin::is_line_valid(string line)
{
	int		i = -1;
    string date;
    string num;
	string::iterator	it;
	
    if (line.size() < 13)
    {
        cout << "Error: bad input => " << line << "\n";
        return false;
    }
    date = line.substr(0, 10);
	num = line.substr(13);
	it = num.begin();
	while (it != num.end())
	{
		if (isdigit(*it) == 0 && *it != '.')
		{
			//cout << *it << " <= \n";
			if (*it == '-')
			{
        		cout << "Error: not a positive number => " << line << "\n";
			}
			else
				cout << "Error1: bad input => " << line << "\n";
			return false;
		}
		it++;
	}
    while (++i < 10)
	{
		if ((i == 4 || i == 7) && date[i] != '-')
		{
        	cout << "Error2: bad input => " << line << "\n";
			return false;
		}
		else if (isdigit(date[i]) == 0 && (i != 4 && i != 7))
		{
        	cout << "Error3: bad input => " << line << "\n";
			return false;
		}
	}

	if (date < data_map.begin()->first || date > data_map.rbegin()->first)
    {
        cout << "Error: " << date << " is out of range.\n";
        return false;
    }

    return true;
}
    
int    Bitcoin::fill_map()
{
    float                               num;
    float                               sum;
	int									prec;
	int									sum_prec;
    std::stringstream                   ss;
    string                              line;
    string                              date;
    string                              nb_str;
    std::fstream                        input(input_name.c_str());
    std::fstream                        data(data_name.c_str());
    std::map<string, float>::iterator    it;

    if (!input || !data)
    {
        cout << "Invalid filename\n";
        input.close();
        data.close();
        return 1;
    }
    std::getline(data, line);
    while (std::getline(data, line))
    {
        ss.str(line.substr(11));
        ss >> num;
        ss.clear();
        ss.str("");
        date = line.substr(0, 10);
        data_map[date] = num;
    }
    std::getline(input, line);
    while (std::getline(input, line))
    {
        if (!is_line_valid(line))
            continue;
        date = line.substr(0, 10);
        if (data_map.find(date) == data_map.end())
            date = findnearest(date);
        ss.str(line.substr(13));
        ss >> num;
        if (num >= 1000 || num <= 0)
        {
			if (num >= 1000)
            	cout << "Error: number is too large.\n";
			else
            	cout << "Error: number is too small.\n";
        	ss.clear();
			ss.str("");
            continue;
        }
        ss.clear();
		ss.str("");
        sum = data_map[date] * num;
		ss << num;
		nb_str = ss.str();
        ss.clear();
		ss.str("");
		if (nb_str.find('.') != std::string::npos)
			prec = (nb_str.substr(nb_str.find('.') + 1).length());
		nb_str.clear();
		ss << sum;
		nb_str = ss.str();
        ss.clear();
		ss.str("");
		if (nb_str.find('.') != std::string::npos && nb_str.find('+') == std::string::npos)
		{
			sum_prec = (nb_str.substr(nb_str.find('.') + 1).length());
		}
		else
			sum_prec = 0;
        cout << std::fixed << std::setprecision(prec) << line.substr(0, 10) << " => " << num << " = ";
		cout << std::fixed << std::setprecision(sum_prec) << sum << "\n";
    }
    return 0;
}
