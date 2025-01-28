#ifndef RPN_HPP
# define RPN_HPP
# include <stack>

using std::string;
using std::stack;

class Rpn
{
private:
        stack<int> mstack;
public:
        Rpn();
        ~Rpn();
        Rpn(Rpn &);
        Rpn &operator=(const Rpn&);
        int operations(char *av);
		const stack<int>	&get_stack() const;
};

#endif
