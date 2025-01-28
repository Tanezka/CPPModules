#include <iostream>
#include "Array.hpp"

#define MAX_VAL 10
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    
	Array<int> tmp = numbers;    
	Array<int> test(tmp);

	std::cout << "before modification test[0]: " << test[0] << "\n";
	numbers[0] -= 1;
	std::cout << "after modification test[0]: " << test[0] << "\n";

	numbers[0] += 1; //original state

	std::cout << "before modification number[0]: " << numbers[0] << "\n";
	tmp[0] += 1;
	std::cout << "after modification number[0]: " << numbers[0] << "\n";

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
