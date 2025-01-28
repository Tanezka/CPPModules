#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>

class	Span
{
private:
	unsigned int		max_size;
	std::vector<int>	vector;
public:
		Span();
		~Span();
		Span(const Span &tmp);
        Span &operator=(const Span &source);
		Span(unsigned int nb);
		int		shortestSpan();
		int		longestSpan();
		void	addNumber(int nb);
		std::vector<int>::iterator			begin();
		std::vector<int>::const_iterator	begin() const;
		std::vector<int>::iterator			end();
		std::vector<int>::const_iterator	end() const;
		unsigned	int						size() const;
		void								fill();
};
#endif
