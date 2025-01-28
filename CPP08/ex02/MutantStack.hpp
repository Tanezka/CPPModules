#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>

template <typename T>
class	MutantStack: public std::stack<T, std::deque<T> >
{
private:
		//std::deque<T> original;
public:
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;
		
		MutantStack<T>() : std::stack<T>()
		{
		
		};
		
		MutantStack<T>(const MutantStack<T>& source)
		{
			*this = source;
		};
		
		~MutantStack<T>()
		{

		};

		MutantStack<T>&	operator=(const MutantStack<T>& source)
		{
			if (this != &source)
				this->c = source.c;
			return (*this);
		}

		iterator begin()
		{
			return (this->c.begin());
		}

		iterator end()
		{
			return (this->c.end());
		}

		const_iterator begin() const
		{
			return (this->c.begin());
		}

		const_iterator end() const
		{
			return (this->c.end());
		}
		
		reverse_iterator rbegin()
		{
			return (this->c.rbegin());
		}

		reverse_iterator rend()
		{
			return (this->c.rend());
		}
		
		const_reverse_iterator rbegin() const
		{
			return (this->c.rbegin());
		}

		const_reverse_iterator rend() const
		{
			return (this->c.rend());
		}
		
		void	push(T nb)
		{
			this->c.push_back(nb);
			//original.push_front(nb);
		}

		void 	pop()
		{
			this->c.pop_back();
			//original.pop_front();
		}
};

#endif
