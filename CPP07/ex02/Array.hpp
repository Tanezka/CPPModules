#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <stdexcept>

template <typename T>
class	Array
{
private:
		T				*array;
		unsigned int	array_size;

public:
		Array() : array(NULL), array_size(0)
		{

		}
		
		Array(unsigned int nb):array(new T[nb]), array_size(nb)
		{

		}
		
		~Array()
		{
			if (array != NULL)
				delete[] array;
		}
		
		Array(const Array &tmp): array(NULL), array_size(0)
		{
			*this = tmp;
		}
        
		Array &operator=(const Array &source)
		{
			if (array != NULL)
				delete[] array;
			if (source.size() == 0)
				return (*this);
			array = new T[source.size()];
			array_size = source.size();
			unsigned int	i = 0;
			while (i < source.size())
			{
				array[i] = source.array[i];
				i++;
			}
			return (*this);
		}

		T &operator[](unsigned int nb)
		{
			if (nb >= array_size || nb < 0)
				throw Array<T>::my_exception();
			return array[nb];
		}

		const T operator[](unsigned int nb) const
		{
			if (nb >= array_size || nb < 0)
				throw Array<T>::my_exception();
			return array[nb];		
		}

		unsigned int	size() const
		{
			return (array_size);
		}

		class	my_exception : public std::exception
		{
		public:
			virtual const char	*what() const throw();
		};
		
};

	template<typename T>
	const char* Array<T>::my_exception::what() const throw()
	{
		return ("Invalid index!");
	}
#endif
