#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <algorithm>
# include <map>
# include <string>

using std::map;
using std::string;

class Bitcoin
{
private:
        string          data_name;
        string          input_name; 
        map<string, float> data_map;
public:
        Bitcoin();
        Bitcoin(string av);
        ~Bitcoin();
        Bitcoin(Bitcoin &);
        Bitcoin &operator=(const Bitcoin&);
        int     fill_map();
        string  findnearest(string date);
        bool    is_line_valid(string line);
		const	map<string, float>	&get_map() const;
};

#endif
