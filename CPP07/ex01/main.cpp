#include <iostream>
#include "iter.hpp"


int main(void) 
{
	//double a[] = {4, 3, 2, 1};
	//void (*temp_func)(double&) = add_one<double>;
	
	//int a[] = {0, 21, 45, 7};
	//void (*temp_func)(int&) = add_one<int>;
	
	//char a[] = "asla";
	//void (*temp_func)(char&) = add_one<char>;
	
	//float a[] = {1, 2, 3, 4};
	//void (*temp_func)(float&) = add_one<float>;

	::iteration(a, 4, temp_func);
	int i = -1;
	while (++i < 4)
		std::cout << a[i] << "\n";
	return 0;
}
