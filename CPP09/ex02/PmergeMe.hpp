#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <list>
# include <vector>

class	Pmergeme
{
private:
		std::vector<unsigned int>   vec;
        std::list<unsigned int>     li;
public:
        Pmergeme();
        ~Pmergeme();
        Pmergeme(Pmergeme &);
        Pmergeme &operator=(const Pmergeme&);
        int merge_insert(char **av);
        int proccess_numbers(char **av);
		std::vector<unsigned int>	merge_sort(std::vector<unsigned int> a);
		std::list<unsigned int>	merge_sort(std::list<unsigned int> a);
		std::vector<unsigned int>	merge(std::vector<unsigned int> a, std::vector<unsigned int> b);
		std::list<unsigned int>	merge(std::list<unsigned int> a, std::list<unsigned int> b);
		const	std::vector<unsigned int>	&get_vec() const;
		const	std::list<unsigned int>		&get_li()  const;
};

#endif
